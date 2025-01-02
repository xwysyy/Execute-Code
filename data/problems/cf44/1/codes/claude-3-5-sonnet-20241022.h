#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &l, int &r, vector<int> &a) {
        // dp[i] stores the maximum number of rounds that can be won
        // considering cards from index i to end
        vector<int> dp(n + 1, 0);
        
        // Start from the end of the array
        for (int i = n - 1; i >= 0; i--) {
            // Initialize with the result without taking any cards from position i
            dp[i] = dp[i + 1];
            
            // Try taking j cards starting from position i
            long long sum = 0;
            for (int j = 0; i + j < n && j < n; j++) {
                sum += a[i + j];
                // If sum is within range [l,r], we can win this round
                if (sum >= l && sum <= r) {
                    dp[i] = max(dp[i], 1 + dp[i + j + 1]);
                }
                // If sum exceeds r, no point in adding more cards
                if (sum > r) break;
            }
        }
        
        return dp[0];
    }
};


#endif