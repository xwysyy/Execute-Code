#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<vector<int>> &a) {   
        long long result = 0;
        for (int d = 0; d < n; ++d) {
            int minVal = 0;
            for (int i = 0; i + d < n; ++i) {
                int val = a[i][i + d];
                if (val < minVal) {
                    minVal = val;
                }
            }
            if (minVal < 0) {
                int needed = abs(minVal);
                result += needed;
                for (int i = 0; i + d < n; ++i) {
                    a[i][i + d] += needed;
                }
            }
        }
        for (int d = 1; d < n; ++d) {
            int minVal = 0;
            for (int i = 0; i + d < n; ++i) {
                int val = a[i + d][i];
                if (val < minVal) {
                    minVal = val;
                }
            }
            if (minVal < 0) {
                int needed = abs(minVal);
                result += needed;
                for (int i = 0; i + d < n; ++i) {
                    a[i + d][i] += needed;
                }
            }
        }
        // Final check for any remaining lakes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] < 0) {
                    return -1; // Impossible to fill all lakes
                }
            }
        }
        return result;
    }
};


#endif