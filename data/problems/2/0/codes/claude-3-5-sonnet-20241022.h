#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution {
public:
    int solve(int N, int V, std::vector<int>& v, std::vector<int>& w) {
        // Create a DP table
        vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));
        
        // Fill the DP table
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j <= V; j++) {
                // Don't take item i-1
                dp[i][j] = dp[i-1][j];
                
                // Take item i-1 if possible
                if(j >= v[i-1]) {
                    dp[i][j] = max(dp[i][j], 
                                 dp[i-1][j-v[i-1]] + w[i-1]);
                }
            }
        }
        
        return dp[N][V];
    }
};

/*

This solution uses dynamic programming to solve the problem:

1. We create a 2D DP table where `dp[i][j]` represents the maximum value we can achieve using first i items and a capacity of j.

2. For each item i and capacity j:
   - We have two choices:
     * Don't take the item: `dp[i][j] = dp[i-1][j]`
     * Take the item if possible: `dp[i][j] = dp[i-1][j-v[i-1]] + w[i-1]`
   - We take the maximum of these two choices

3. The solution will be in `dp[N][V]`

Time Complexity: O(N*V)
Space Complexity: O(N*V)

For the example:
N = 3, V = 4, v = [4, 3, 1], w = [1, 2, 1]

The optimal solution is to take the second and third items:
- Second item: volume = 3, value = 2
- Third item: volume = 1, value = 1
Total volume = 4 (≤ V), Total value = 3

Therefore, the maximum value possible is 2.

*/

#endif