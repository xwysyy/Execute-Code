#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &l, int &r, vector<int> &a) {
        // dp[i] represents the maximum number of winning rounds possible
        // starting from index i
        vector<int> dp(n + 1, -1);
        dp[n] = 0;  // base case: no cards left means 0 winning rounds
        
        // Start from the end and work backwards
        for (int i = n - 1; i >= 0; i--) {
            long long sum = 0;
            int maxWins = 0;
            
            // Try taking j cards starting from position i
            for (int j = 1; i + j <= n; j++) {
                sum += (long long)a[i + j - 1];
                // If sum is within bounds, we can potentially win this round
                if (sum >= l && sum <= r) {
                    maxWins = max(maxWins, 1 + dp[i + j]);
                } else if (sum > r) {
                    // No need to check further as sum will only increase
                    break;
                } else {
                    maxWins = max(maxWins, dp[i + j]);
                }
            }
            dp[i] = maxWins;
        }
        
        return dp[0];
    }
};


#endif