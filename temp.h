#ifndef TEMP_H
#define TEMP_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
extern long long comparisons;


struct matrix {
	int r1;
	int c1;
	int r2;
	int c2;

};

void splitLines(const vector<string>& grid, int R, int C, vector<pair<string, vector<pair<int, int>>>>& lines);
#endif 

