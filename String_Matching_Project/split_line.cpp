#include "split_line.h"
#include <iostream>
#include <vector>
#include <string>

long long comparisons = 0;

void splitLines(const vector<string>& grid, int R, int C, vector<pair<string, vector<pair<int, int>>>>& lines){
    for (int row = 0; row < R; row++) {
        string s;
        vector<pair<int, int>> pos;

        for (int col = 0; col < C; col++) {
            s.push_back(grid[row][col]);
            pos.emplace_back(row, col);
        }

        lines.emplace_back(s, pos);
    }

    for (int col = 0; col < C; col) {
        string s;
        vector<pair<int, int>> pos;

        for (int row = 0; row < R; row++) {
            s.push_back(grid[row][col]);
            pos.emplace_back(row, col);
        }
        lines.emplace_back(s, pos);
    }
}
