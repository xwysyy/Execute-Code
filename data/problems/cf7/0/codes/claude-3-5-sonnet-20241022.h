#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {
        // dp[i][j] represents the maximum magazines that can be saved 
        // considering boxes 0 to i, with j lids moved to the left
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        // Base case: first box
        if (s[0] == '1') {
            dp[0][0] = a[0];  // keep lid on first box
            dp[0][1] = 0;     // can't move lid left from first box
        }
        
        // For each box
        for (int i = 1; i < n; i++) {
            // If current box has no lid
            if (s[i] == '0') {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            }
            // If current box has lid
            else {
                // Option 1: Keep lid where it is
                dp[i][0] = dp[i-1][0] + a[i];
                
                // Option 2: Move lid to left box
                // We can save magazines in box i-1 instead of box i
                dp[i][1] = max(dp[i-1][0] + a[i-1], dp[i-1][1]);
            }
        }
        
        // Return maximum of keeping all lids in place or moving some left
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


#endif