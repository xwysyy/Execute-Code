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
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        
        // Base cases
        dp[0][0] = 0;  // not colored
        dp[0][1] = a[0] + 1;  // colored
        
        // Fill dp table
        for (int i = 1; i < n; i++) {
            // If current element is not colored
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            
            // If current element is colored
            // We can only color if previous element is not colored
            dp[i][1] = dp[i-1][0] + a[i] + 1;
        }
        
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


#endif