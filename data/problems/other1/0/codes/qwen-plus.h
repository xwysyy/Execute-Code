#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &N, int &V, vector<int> &v, vector<int> &w) {   
        vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= V; ++j) {
                if (j >= v[i - 1]) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][V];
    }
};


#endif