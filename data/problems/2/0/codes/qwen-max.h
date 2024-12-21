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
        // Initialize the DP table with dimensions (N+1) x (V+1)
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(V + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j <= V; ++j)
            {
                // If the current item can be included in the backpack
                if (v[i - 1] <= j)
                {
                    // Choose the maximum value between including and excluding the current item
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
   - We create a 2D DP table `dp` of size `(N+1) x (V+1)` initialized to 0. `dp[i][j]` will store the maximum value that can be obtained by considering the first `i` items with a total volume not exceeding `j`.

2. **Filling the DP Table**:
   - We iterate over each item from 1 to `N`.
   - For each item, we iterate over each possible volume from 0 to `V`.
   - If the current item's volume `v[i-1]` is less than or equal to the current volume `j`, we have two choices:
     - Include the current item: `dp[i-1][j - v[i-1]] + w[i-1]`
     - Exclude the current item: `dp[i-1][j]`
     - We take the maximum of these two values.
   - If the current item's volume is greater than the current volume `j`, we cannot include the item, so we carry forward the value from the previous row: `dp[i-1][j]`.

3. **Result**:
   - The final answer will be in `dp[N][V]`, which represents the maximum value that can be obtained by considering all `N` items with a total volume not exceeding `V`.

This approach ensures that we consider all possible combinations of items and volumes, and it runs in `O(N * V)` time, which is efficient given the constraints.

*/

#endif