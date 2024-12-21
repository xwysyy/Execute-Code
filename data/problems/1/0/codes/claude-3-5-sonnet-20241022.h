#ifndef CLAUDE-3-5-SONNET-20241022_H
#define CLAUDE-3-5-SONNET-20241022_H
#include <bits/stdc++.h>
using namespace std;

/*

Here's a solution using the 0/1 Knapsack dynamic programming approach:

*/

class Solution {
public:
    int solve(int N, int V, vector<int>& v, vector<int>& w) {
        // Create a 2D DP table 
        // dp[i][j] represents the max value achievable 
        // considering first i items with capacity j
        vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));
        
        // Iterate through all items
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= V; j++) {
                // If current item volume exceeds current capacity, 
                // can't include this item
                if (v[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    // Max of two choices:
                    // 1. Don't include current item 
                    // 2. Include current item if it fits
                    dp[i][j] = max(
                        dp[i-1][j],  // not including current item
                        dp[i-1][j-v[i-1]] + w[i-1]  // including current item
                    );
                }
            }
        }
        
        // Return max value possible
        return dp[N][V];
    }
};

/*

This solution uses the classic 0/1 Knapsack dynamic programming approach:

1. Create a 2D DP table where:
   - Rows represent items (0 to N)
   - Columns represent capacities (0 to V)
   - `dp[i][j]` represents the maximum value achievable by considering the first `i` items with a capacity of `j`

2. Initialization:
   - First row and column are 0 (base case)

3. DP Recurrence Relation:
   - For each item and each capacity, we have two choices:
     a) Don't include the current item: `dp[i-1][j]`
     b) Include the current item if it fits: `dp[i-1][j-v[i-1]] + w[i-1]`
   - Take the maximum of these two choices

4. Time Complexity: O(N * V)
5. Space Complexity: O(N * V)

Key points:
- `v[i-1]` is the volume of the current item
- `w[i-1]` is the value of the current item
- `dp[i-1][j-v[i-1]]` represents the max value achievable before adding current item
- Final answer is in `dp[N][V]`

For the given example:
- N = 3, V = 4
- v = [4, 3, 1]
- w = [1, 2, 1]
- Maximum value = 2 (can choose items with volumes 3 and 1)

*/

#endif