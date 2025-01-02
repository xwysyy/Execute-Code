#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &N, int &V, vector<int> &v, vector<int> &w) {
        // Initialize a DP array with size V+1, filled with 0
        vector<int> dp(V + 1, 0);
        
        // Iterate through each item
        for (int i = 0; i < N; i++) {
            // Iterate through the capacity from V down to v[i]
            for (int j = V; j >= v[i]; j--) {
                // Update the DP array with the maximum value
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        // The maximum value is stored in dp[V]
        return dp[V];
    }
};


#endif