#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // dp[i] stores the maximum number of beautiful segments up to index i
        vector<int> dp(n + 1, 0);
        
        // prefix sum to quickly calculate segment sums
        vector<long long> psum(n + 1, 0);
        for(int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + a[i];
        }
        
        // For each ending position j
        for(int j = 0; j < n; j++) {
            // Copy previous best result
            dp[j + 1] = dp[j];
            
            // Try all possible starting positions i for the current segment
            for(int i = j; i >= 0; i--) {
                // Calculate sum of current segment [i,j]
                long long segSum = psum[j + 1] - psum[i];
                
                if(segSum == 0) {
                    // If segment is beautiful, take max of:
                    // 1. Current best for position j
                    // 2. Best result before segment (dp[i]) plus 1 for current segment
                    dp[j + 1] = max(dp[j + 1], dp[i] + 1);
                }
            }
        }
        
        return dp[n];
    }
};


#endif