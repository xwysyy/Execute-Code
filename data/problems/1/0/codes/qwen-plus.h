#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution {
public:
    int solve(int N, int V, std::vector<int> &v, std::vector<int> &w) {
        // Initialize the DP table
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(V + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= V; ++j) {
                // If the current item's volume is greater than the current capacity, skip it
                if (v[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // Otherwise, consider both taking and not taking the item
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
                }
            }
        }

        // The answer is in dp[N][V]
        return dp[N][V];
    }
};

/*

### Explanation:
1. **Initialization**: We initialize a 2D vector `dp` of size `(N+1) x (V+1)` with all elements set to 0. This table will store the maximum value that can be achieved with a given number of items and a given knapsack capacity.

2. **Filling the DP Table**:
   - For each item `i` from 1 to `N`:
     - For each possible knapsack capacity `j` from 0 to `V`:
       - If the volume of the current item `v[i-1]` is greater than the current capacity `j`, we cannot take this item, so we carry forward the value from the previous row (`dp[i-1][j]`).
       - Otherwise, we have two choices: either take the item or not take it. We choose the one that gives the maximum value:
         - Not taking the item: `dp[i-1][j]`
         - Taking the item: `dp[i-1][j-v[i-1]] + w[i-1]`

3. **Result**: The final result, which is the maximum value that can be obtained, is stored in `dp[N][V]`.

This approach ensures that we explore all possible combinations of items while adhering to the knapsack's capacity constraint, leading to an optimal solution.

*/

#endif