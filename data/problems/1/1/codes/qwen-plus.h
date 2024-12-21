#ifndef QWEN-PLUS_H
#define QWEN-PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use a dynamic programming approach to implement the 0/1 Knapsack algorithm. The idea is to create a DP table where `dp[i][j]` represents the maximum value that can be obtained with the first `i` items and a knapsack capacity of `j`.

Here's how you can implement it:

*/

#include <vector>
using namespace std;

class Solution {
public:
    int solve(int N, int V, vector<int>& v, vector<int>& w) {
        // Create a DP table with dimensions (N+1) x (V+1)
        vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));
        
        // Fill the DP table
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= V; ++j) {
                // If the current item's volume exceeds the current capacity, skip it
                if (v[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // Otherwise, consider both taking and not taking the current item
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
                }
            }
        }
        
        // The answer will be in dp[N][V]
        return dp[N][V];
    }
};

/*

### Explanation:
1. **Initialization**: We initialize a 2D vector `dp` of size `(N+1) x (V+1)` filled with zeros. This table will store the maximum value that can be achieved with the first `i` items and a knapsack capacity of `j`.

2. **Filling the DP Table**:
   - For each item `i` from `1` to `N`:
     - For each possible capacity `j` from `0` to `V`:
       - If the volume of the current item `v[i-1]` is greater than the current capacity `j`, then we cannot include this item, so `dp[i][j]` remains the same as `dp[i-1][j]`.
       - Otherwise, we have two choices: either include the item or exclude it. We take the maximum value between these two choices:
         - Not including the item: `dp[i-1][j]`
         - Including the item: `dp[i-1][j - v[i-1]] + w[i-1]`

3. **Result**: The final result, which is the maximum value that can be obtained with all `N` items and a knapsack capacity of `V`, is stored in `dp[N][V]`.

This approach ensures that we explore all possible combinations of items while adhering to the knapsack's capacity constraint, leading to an optimal solution.

*/

#endif