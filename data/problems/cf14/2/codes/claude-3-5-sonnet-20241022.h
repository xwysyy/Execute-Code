#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        // Create dp array where dp[i][0] represents maximum sum ending at i without flipping i
        // and dp[i][1] represents maximum sum ending at i with flipping i
        vector<vector<long long>> dp(n, vector<long long>(2));
        
        // Base case: first element
        dp[0][0] = a[0];
        dp[0][1] = -a[0];
        
        // Fill dp array
        for(int i = 1; i < n; i++) {
            // Without flipping current element
            dp[i][0] = max(dp[i-1][0] + a[i],      // Don't flip previous
                          dp[i-1][1] - a[i-1] + a[i]); // Flip previous
            
            // With flipping current element
            dp[i][1] = max(dp[i-1][0] - a[i],      // Don't flip previous
                          dp[i-1][1] - a[i-1] - a[i]); // Flip previous
        }
        
        // Return maximum of last element flipped or not flipped
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


#endif