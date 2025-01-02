#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &N, int &V, vector<int> &v, vector<int> &w) {  
        vector<int> dp(V + 1, 0);  // Initialize a dp array with size V+1 and all elements 0

        // Loop through each item
        for (int i = 0; i < N; ++i) {
            // Loop backward through the dp array from V to v[i]
            for (int j = V; j >= v[i]; --j) {
                // Update the dp value to take the maximum of not taking or taking the current item
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        return dp[V];  // The maximum value achievable with full capacity V
    }
};


#endif