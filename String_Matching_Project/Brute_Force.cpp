#include "Brute_force.h"
#include "split_line.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std; 

// Brute-force 
// Complexity: O((n - m + 1) * m)
static const long long BASE = 31;
static const long long MOD = 1000000009LL;
vector<int> brute_force_search(const string& text, const string& pattern) {
	vector <int> res; 
	int n = text.length(); 
	int m = pattern.length();
	if (m == 0 || m > n) return res;

	for (int i = 0; i <= n - m; i++) {
		int j = 0;
		while (j < m && text[i + j] == pattern[j]) {
			++comparisons;
			if (text[i + j] != pattern[j]) break;
			j++;
		}
		if (j == m) {
			res.push_back(i); 
		}
	
	}
	return res; 
}
