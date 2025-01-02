#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // For n=1, the answer is simply the element value + 1
        if (n == 1) return a[0] + 1;
        
        // dp[i][0] = max score up to i without taking i
        // dp[i][1] = max score up to i taking i
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        // Base cases
        dp[0][0] = 0;  // not taking first element
        dp[0][1] = a[0] + 1;  // taking first element
        
        // For each position
        for (int i = 1; i < n; i++) {
            // If we don't take current element
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            
            // If we take current element, we can't take previous element
            dp[i][1] = dp[i-1][0] + a[i] + 1;
        }
        
        // Return maximum of taking or not taking last element
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


#endif