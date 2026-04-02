#ifndef BM_H
#define BM_H
#include <string>
#include <vector>
#include "match.h"
using namespace std;

void badCharHeuristic(const string& str, int size, vector<int>& badchar);

void searchDirectionBM(const vector<vector<char>>& grid, const string& pat, const vector<int>& badchar, int sr, int sc, int dr, int dc, vector<Match>& allMatches, long long& compCount);

void searchMatrixBM(const vector<vector<char>>& grid, const string& pat, vector<Match>& allMatches, long long& compCount);

#endif