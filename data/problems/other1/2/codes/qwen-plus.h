#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &N, int &V, vector<int> &v, vector<int> &w) {   
        vector<int> dp(V + 1, 0);
        
        for (int i = 0; i < N; ++i) {
            for (int j = V; j >= v[i]; --j) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};


#endif