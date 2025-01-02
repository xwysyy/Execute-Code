#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &N, int &V, vector<int> &v, vector<int> &w) {
        // Create a DP array to store maximum value for each capacity
        vector<int> dp(V + 1, 0);
        
        // Process each item
        for (int i = 0; i < N; i++) {
            // Traverse the capacity array backwards
            for (int j = V; j >= v[i]; j--) {
                // Update the dp array if taking the current item is beneficial
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        // The maximum value that can fit in the backpack with capacity V
        return dp[V];
    }
};


#endif