#include <iostream>
#include <string>
#include <vector>
#include "BM.h"
#include "match.h"
using namespace std;

void badCharHeuristic(const string& str, int size, vector<int>& badchar) {
    for (int i = 0; i < 256; i++) badchar[i] = -1;
    for (int i = 0; i < size; i++) badchar[(int)str[i]] = i;
}
void searchDirectionBM(const vector<vector<char>>& grid, const string& pat, const vector<int>& badchar, int sr, int sc, int dr, int dc, vector<Match>& allMatches, long long& compCount) {
    int R = grid.size(), C = grid[0].size(), M = pat.length();
    int N = (dr == 0) ? C : R;
    int s = 0;
    while (s <= (N - M)) {
        int j = M - 1;
        while (j >= 0) {
            compCount++;
            int r = sr + (s + j) * dr;
            int c = sc + (s + j) * dc;
            if (pat[j] == grid[r][c]) 
                j--;
            else 
                break;
        }
        if (j < 0) {
            int start_r = sr + s * dr;
            int start_c = sc + s * dc;
            int end_r = start_r + (M - 1) * dr;
            int end_c = start_c + (M - 1) * dc;
            allMatches.push_back({ start_r, start_c, end_r, end_c });
            if (s + M < N) {
                int next_r = sr + (s + M) * dr;
                int next_c = sc + (s + M) * dc;
                s += M - badchar[(int)grid[next_r][next_c]];
            }
            else s++;
        }
        else {
            int r = sr + (s + j) * dr;
            int c = sc + (s + j) * dc;
            s += max(1, j - badchar[(int)grid[r][c]]);
        }
    }
}
void searchMatrixBM(const vector<vector<char>>& grid, const string& pat, vector<Match>& allMatches, long long& compCount) {
    int R = grid.size(), C = grid[0].size(), M = pat.length();
    if (M > R && M > C) return;
    vector<int> badchar(256);
    badCharHeuristic(pat, M, badchar);
    if (M <= C) {
        for (int r = 0; r < R; r++) searchDirectionBM(grid, pat, badchar, r, 0, 0, 1, allMatches, compCount);
    }
    if (M <= R) {
        for (int c = 0; c < C; c++) searchDirectionBM(grid, pat, badchar, 0, c, 1, 0, allMatches, compCount);
    }
}