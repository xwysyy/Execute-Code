#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &N, int &V, vector<int> &v, vector<int> &w) {
        vector<int> dp(V + 1, 0); // Initialize DP array with 0
        
        // Iterate over all items
        for (int i = 0; i < N; i++) {
            // Traverse dp array from capacity V down to v[i]
            for (int j = V; j >= v[i]; j--) {
                // Update dp[j] to be the maximum of not taking or taking the item
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        // The maximum value for a backpack of capacity V is now in dp[V]
        return dp[V];
    }
};


#endif