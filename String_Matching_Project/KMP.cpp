#include <iostream>
#include <string>
#include <vector>
#include "KMP.h"
#include "match.h"
using namespace std;

void buildLPS(const string& pat, vector<int>& lps) {
	int len = 0, i = 1;
	lps[0] = 0;
	while (i < pat.length()) {
		if (pat[i] == pat[len]) {
			len++; 
			lps[i] = len;
			i++;
		}
		else {
			if 
				(len != 0) len = lps[len - 1];
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

void searchDirection(const vector<vector<char>>& grid, const string& pat, const vector<int>& lps, int sr, int sc, int dr, int dc, vector<Match>& allMatches, long long& compCount) {
    int R = grid.size(), C = grid[0].size(), M = pat.length();
    int i = 0, j = 0;
    int r = sr, c = sc;
    int n = (dr == 0) ? C : R;
    while (i < n) {
        compCount++;
        if (grid[r][c] == pat[j]) {
            i++; j++;
            r += dr; c += dc;
            if (j == M) {
                int end_r = r - dr;
                int end_c = c - dc;
                int start_r = end_r - (M - 1) * dr;
                int start_c = end_c - (M - 1) * dc;
                allMatches.push_back({ start_r, start_c, end_r, end_c });
                j = lps[j - 1];
            }
        }
        else {
            if (j != 0) j = lps[j - 1];
            else {
                i++;
                r += dr; c += dc;
            }
        }
    }
}
void searchMatrix(const vector<vector<char>>& grid, const string& pat, vector<Match>& allMatches, long long& compCount) {
    int R = grid.size(), C = grid[0].size(), M = pat.length();
    vector<int> lps(M);
    buildLPS(pat, lps);
    for (int r = 0; r < R; r++) searchDirection(grid, pat, lps, r, 0, 0, 1, allMatches, compCount);
    for (int c = 0; c < C; c++) searchDirection(grid, pat, lps, 0, c, 1, 0, allMatches, compCount);
}
