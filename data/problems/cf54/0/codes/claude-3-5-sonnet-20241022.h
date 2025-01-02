#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // dp[i] represents the maximum number of beautiful segments up to index i
        vector<int> dp(n + 1, 0);
        
        // For each possible ending position
        for (int i = 0; i < n; i++) {
            // Take maximum from previous state
            dp[i + 1] = dp[i];
            
            // Try all possible segments ending at i
            int sum = 0;
            for (int j = i; j >= 0; j--) {
                sum += a[j];
                if (sum == 0) {
                    // If we found a beautiful segment [j,i],
                    // update dp[i+1] with max of current value and
                    // dp[j] (segments before j) + 1 (current segment)
                    dp[i + 1] = max(dp[i + 1], dp[j] + 1);
                }
            }
        }
        
        return dp[n];
    }
};


#endif