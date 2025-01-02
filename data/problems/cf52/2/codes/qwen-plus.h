#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<vector<int>> &a) {   
        // write your code here
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            int minMagicRequired = 0;
            for (int j = 0; i + j < n && j + i < n; ++j) {
                if (a[i + j][i + j] < 0) {
                    minMagicRequired = max(minMagicRequired, -a[i + j][i + j]);
                }
            }
            result += minMagicRequired;
            for (int j = 0; i + j < n && j + i < n; ++j) {
                a[i + j][i + j] += minMagicRequired;
            }
        }
        return result;
    }
};


#endif