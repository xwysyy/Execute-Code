#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 1) return a[0] + 1;
        
        // dp[i][0] = max score when i-th element is not colored
        // dp[i][1] = max score when i-th element is colored
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        // Base cases
        dp[0][0] = 0;  // not colored
        dp[0][1] = a[0] + 1;  // colored
        
        // For each position
        for (int i = 1; i < n; i++) {
            // If current not colored, we can take either state from previous
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            
            // If current colored, we can only take previous not colored
            // New score = previous score when not colored + 1 (new count)
            // Then update max value if current is larger
            dp[i][1] = dp[i-1][0] + 1;
            dp[i][1] = max(dp[i][1] + a[i] - 1, dp[i][1]);
        }
        
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


#endif