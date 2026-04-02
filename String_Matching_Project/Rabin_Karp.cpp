#include "Rabin_Karp.h"
#include "split_line.h"
#include <iostream>
#include <vector>
#include <string>

static const long long BASE = 31;
static const long long MOD = 1000000009LL;

//  Rabin-Karp
//  Using Rolling Hash
//  Base = 31, Mod = 1e9+9  
//  Complexity: O(n+m) for average case and O(n*m) for worst case (many collision).
vector<int> Rabin_Karp_search(const string& text, const string& pattern) {
	vector<int> res;
	int n = text.size();
	int m = pattern.size();

	if (m == 0 || m > n) return res;

	long long hash_pattern = 0;
	long long hash_text = 0;
	long long power = 1;
	for (int i = 0; i < m - 1; i++) {
		power = power * BASE % MOD;
	}

	for (int i = 0; i < m; i++) {
		hash_pattern = (hash_pattern * BASE + (pattern[i] - 'a' + 1)) % MOD;
		hash_text = (hash_text * BASE + (text[i] - 'a' + 1)) % MOD;
	}

	for (int i = 0; i <= n - m; ++i) {
		if (hash_pattern == hash_text) { // check
			bool check = true;
			for (int j = 0; j < m; ++j) {
				++comparisons;
				if (text[i + j] != pattern[j]) {
					check = false;
					break;
				}
			}
			if (check) res.push_back(i);
		}
		// Update the rolling hash for next window
		if (i < n - m) {
			hash_text = (hash_text - (long long)(text[i] - 'a' + 1) * power % MOD + MOD) % MOD;
			hash_text = (hash_text * BASE + (text[i + m] - 'a' + 1)) % MOD;
		}
	}
	return res;
}
