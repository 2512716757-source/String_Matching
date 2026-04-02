#ifndef TEMP_H
#define TEMP_H
#include <iostream>
#include <vector>
#include <string>
#include "match.h"
using namespace std;
extern long long comparisons;

void splitLines(const vector<string>& grid, int R, int C, vector<pair<string, vector<pair<int, int>>>>& lines);
#endif 

