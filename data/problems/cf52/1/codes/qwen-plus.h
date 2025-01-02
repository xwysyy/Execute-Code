#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<vector<int>> &a) {   
        long long result = 0;
        for (int d = 0; d < n; ++d) {
            int min_val = 0;
            for (int i = 0; i + d < n && i < n; ++i) {
                if (a[i][i + d] < min_val) {
                    min_val = a[i][i + d];
                }
                if (d != 0 && a[i + d][i] < min_val) {
                    min_val = a[i + d][i];
                }
            }
            if (min_val < 0) {
                result += abs(min_val);
                for (int i = 0; i + d < n && i < n; ++i) {
                    a[i][i + d] += abs(min_val);
                    if (d != 0) {
                        a[i + d][i] += abs(min_val);
                    }
                }
            }
        }
        return result;
    }
};


#endif