#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "KMP.h"
#include "BM.h"
#include "match.h"
using namespace std;

int main(int argc, char* argv[]) {
    string algo, inputFile, outputFile;
    for (int i = 1; i < argc; ++i) {
        string a = argv[i];
        if (a == "-a" && i + 1 < argc) algo = argv[++i];
        else if (a == "-i" && i + 1 < argc) inputFile = argv[++i];
        else if (a == "-o" && i + 1 < argc) outputFile = argv[++i];
    }

    if (algo.empty() || inputFile.empty() || outputFile.empty()) {
        cerr << "Usage: crossword -a [bf|rk|kmp|bm|ac] -i <input_file> -o <output_file>" << endl;
        return 1;
    }

    ifstream fin(inputFile);
    if (!fin) {
        cerr << "Cannot open input file: " << inputFile << endl;
        return 1;
    }

    int R, C;
    fin >> R >> C;
    vector<string> grid(R);
    for (int row = 0; row < R; row++) {
        grid[row].resize(C);
        for (int col = 0; col < C; col++)
            fin >> grid[row][col];
    }

    int K;
    fin >> K;
    vector<string> words(K);
    for (int k = 0; k < K; k++) fin >> words[k];
    fin.close();

    return 0;
}