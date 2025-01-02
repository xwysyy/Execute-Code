#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        int dp[n];
        memset(dp, 0, sizeof(dp));
        int result = 1;
        dp[0] = 1;
        
        for (int i = 1; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (a[j] >= a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        
        return n - result;
    }
};


#endif