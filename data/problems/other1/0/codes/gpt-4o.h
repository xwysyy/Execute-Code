#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &N, int &V, std::vector<int> &v, std::vector<int> &w) {
        // DP array to store maximum values for each capacity
        std::vector<int> dp(V + 1, 0);
        
        // Iterate over each item
        for (int i = 0; i < N; ++i) {
            // Traverse the dp array backwards to update it based on the current item
            for (int j = V; j >= v[i]; --j) {
                // Update the DP table by considering including the current item
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        // Return the maximum value that can be obtained with the full capacity
        return dp[V];
    }
};


#endif