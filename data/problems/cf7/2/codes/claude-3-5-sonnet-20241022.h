#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {
        // dp[i][j] represents the maximum magazines that can be saved 
        // considering boxes 0 to i, where j indicates if we moved a lid to position i
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        // Initialize first position
        if (s[0] == '1') {
            dp[0][0] = a[0];  // Keep lid at position 0
            dp[0][1] = 0;     // Can't move lid left at position 0
        }
        
        // For each position
        for (int i = 1; i < n; i++) {
            // If current position has no lid
            if (s[i] == '0') {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            }
            // If current position has a lid
            else {
                // Option 1: Keep lid at current position
                dp[i][0] = dp[i-1][0] + a[i];
                
                // Option 2: Move lid to previous position
                dp[i][1] = dp[i-1][0] + a[i-1];
            }
        }
        
        // Return maximum of last position's options
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


#endif