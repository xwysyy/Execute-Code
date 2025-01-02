#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(string &s) {
        int n = s.length();
        vector<vector<int>> table(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                table[i][j] = s[(j - i + n) % n] - '0';
            }
        }

        long long max_area = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = i; k < n; ++k) {
                    for (int l = j; l < n; ++l) {
                        bool all_ones = true;
                        for (int row = i; row <= k; ++row) {
                            for (int col = j; col <= l; ++col) {
                                if (table[row][col] == 0) {
                                    all_ones = false;
                                    break;
                                }
                            }
                            if (!all_ones) break;
                        }
                        if (all_ones) {
                            max_area = max(max_area, (long long)(k - i + 1) * (l - j + 1));
                        }
                    }
                }
            }
        }
        return max_area;
    }
};


#endif