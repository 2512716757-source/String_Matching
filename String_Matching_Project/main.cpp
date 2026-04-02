#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include "KMP.h"
#include "BM.h"
#include "Match.h"
#include "Brute_Force.h"
#include "Rabin_Karp.h"
using namespace std;
long long compCount = 0;

int main(int argc, char* argv[]) {
    string algo, inputFile, outputFile;
    for (int i = 1; i < argc; ++i) {
        string a = argv[i];
        if (a == "-a" && i + 1 < argc) algo = argv[++i];
        else if (a == "-i" && i + 1 < argc) inputFile = argv[++i];
        else if (a == "-o" && i + 1 < argc) outputFile = argv[++i];
    }
    if (algo.empty() || inputFile.empty() || outputFile.empty()) return 1;
    ifstream fin(inputFile);
    if (!fin) return 1;
    int R, C;
    fin >> R >> C;
    vector<vector<char>> grid(R, vector<char>(C));
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) fin >> grid[row][col];
    }
    int K;
    fin >> K;
    vector<string> words(K);
    for (int k = 0; k < K; k++) fin >> words[k];
    fin.close();
    
    vector<vector<Match>> allRes(K);
    compCount = 0;
    auto start = chrono::high_resolution_clock::now();
    for (int k = 0; k < K; k++) {
        if (algo == "kmp") searchMatrix(grid, words[k], allRes[k], compCount);
        else if (algo == "bm") searchMatrixBM(grid, words[k], allRes[k], compCount);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    
    ofstream fout(outputFile);
    if (!fout) return 1;
    for (int k = 0; k < K; k++) {
        fout << words[k] << ": ";
        if (allRes[k].empty()) fout << "not found\n";
        else {
            for (size_t i = 0; i < allRes[k].size(); i++) {
                fout << "(" << allRes[k][i].r1 << ", " << allRes[k][i].c1 << ") -> (" << allRes[k][i].r2 << ", " << allRes[k][i].c2 << ");";
                if (i < allRes[k].size() - 1) fout << " ";
            }
            fout << "\n";
        }
    }
    fout << "----------------------------------------\n";
    string algoName = "";
    if (algo == "kmp") algoName = "KMP";
    else if (algo == "bm") algoName = "Boyer-Moore";
    else if (algo == "bf") algoName = "Brute Force";
    else if (algo == "rk") algoName = "Rabin-Karp";
    fout << "Algorithm: " << algoName << "\n";
    fout << "Comparisons: " << compCount << "\n";
    fout << "Execution Time: " << duration.count() << " ms\n";
    fout.close();
    return 0;
}