#ifndef KMP_H
#define KMP_H
#include <string>
#include <vector>
#include "match.h"
using namespace std;

void buildLPS(const string& pat, vector<int>& lps);

void searchDirection(const vector<vector<char>>& grid, const string& pat, const vector<int>& lps, int sr, int sc, int dr, int dc, vector<Match>& allMatches, long long& compCount);

void searchMatrix(const vector<vector<char>>& grid, const string& pat, vector<Match>& allMatches, long long& compCount);

#endif