#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &N, int &V, vector<int> &v, vector<int> &w) {
        // Create a DP array to store the maximum value that can be achieved with each capacity
        vector<int> dp(V + 1, 0);
        
        // Iterate over all items
        for (int i = 0; i < N; ++i) {
            // Iterate over the DP array in reverse to prevent overwriting issues
            for (int j = V; j >= v[i]; --j) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        // The maximum value achievable with the full capacity of the backpack
        return dp[V];
    }
};


#endif