#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution {
public:
    int solve(int N, int V, vector<int>& v, vector<int>& w) {
        // Initialize a DP table with dimensions (N+1) x (V+1)
        vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= V; ++j) {
                if (v[i - 1] > j) {
                    // If the current item's volume is greater than the current capacity,
                    // we cannot include this item.
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // Otherwise, take the maximum of including or excluding the current item.
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
1. **Initialization**:
   - We initialize a 2D vector `dp` of size `(N+1) x (V+1)` filled with zeros. This table will store the maximum value that can be achieved for each subproblem.

2. **Filling the DP Table**:
   - For each item `i` from 1 to `N` and each possible volume `j` from 0 to `V`:
     - If the volume of the current item `v[i-1]` is greater than the current capacity `j`, then we cannot include this item, so `dp[i][j]` remains the same as `dp[i-1][j]`.
     - Otherwise, we have two choices: either include the current item or exclude it. We choose the option that gives the maximum value:
       - Including the item: `dp[i-1][j - v[i-1]] + w[i-1]`
       - Excluding the item: `dp[i-1][j]`
     - We set `dp[i][j]` to the maximum of these two values.

3. **Result**:
   - The final result, which is the maximum value that can be obtained, is stored in `dp[N][V]`.

This approach ensures that we explore all possible combinations of items while keeping track of the best solution at each step, leading to an optimal solution within the given constraints.

*/

#endif