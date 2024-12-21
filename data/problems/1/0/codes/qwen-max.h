#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution
{
public:
    int solve(int N, int V, std::vector<int> &v, std::vector<int> &w)
    {
        // Initialize the DP table with size (N+1) x (V+1)
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(V + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j <= V; ++j)
            {
                // If the current item can be included in the knapsack
                if (v[i - 1] <= j)
                {
                    // Max of including the current item or not including it
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
                }
                else
                {
                    // If the current item cannot be included, carry forward the previous value
                    dp[i][j] = dp[i - 1][j];
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
   - We create a 2D vector `dp` of size `(N+1) x (V+1)` and initialize all values to 0. This table will store the maximum value that can be obtained for each subproblem.

2. **Filling the DP Table**:
   - We iterate over each item from 1 to `N`.
   - For each item, we iterate over each possible volume from 0 to `V`.
   - If the current item's volume `v[i-1]` is less than or equal to the current volume `j`, we have two choices:
     - Include the current item: `dp[i-1][j - v[i-1]] + w[i-1]`
     - Exclude the current item: `dp[i-1][j]`
   - We take the maximum of these two choices.
   - If the current item's volume is greater than the current volume `j`, we simply carry forward the value from the previous row: `dp[i-1][j]`.

3. **Result**:
   - The value at `dp[N][V]` will be the maximum value that can be obtained by considering all `N` items with a total volume not exceeding `V`.

This solution has a time complexity of \(O(N \times V)\) and a space complexity of \(O(N \times V)\), which is efficient given the constraints.

*/

#endif