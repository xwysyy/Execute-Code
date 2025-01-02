#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &N, int &V, vector<int> &v, vector<int> &w) {
        // Create a DP table where dp[i][j] represents the maximum value
        // that can be achieved with first i items and capacity j
        vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));
        
        // Fill the DP table
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= V; j++) {
                // Don't take item i-1
                dp[i][j] = dp[i-1][j];
                
                // Take item i-1 if possible
                if (j >= v[i-1]) {
                    dp[i][j] = max(dp[i][j], 
                                 dp[i-1][j - v[i-1]] + w[i-1]);
                }
            }
        }
        
        return dp[N][V];
    }
};


#endif