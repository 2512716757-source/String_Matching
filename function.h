#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> brute_force_search(const string& text, const string& pattern); 
vector<int> rabin_karp_search(const string& text, const string& pattern);

#endif 
