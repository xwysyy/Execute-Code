#ifndef QWEN_CODER_PLUS_H
#define QWEN_CODER_PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution
{
public:
    int solve(int N, int V, std::vector<int> &v, std::vector<int> &w)
    {
        // Create a 2D DP array with dimensions (N+1) x (V+1)
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(V + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j <= V; ++j)
            {
                if (v[i - 1] <= j)
                {
                    // If we include the i-th item, we add its value to the best value we can get with the remaining capacity
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
                }
                else
                {
                    // If we cannot include the i-th item, we carry forward the best value without it
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The answer will be in dp[N][V], which represents the maximum value with all items and full capacity
        return dp[N][V];
    }
};

/*

### Explanation:

1. **Initialization**:
   - We initialize a 2D vector `dp` of size `(N+1) x (V+1)` with all elements set to 0. This table will store the maximum value that can be achieved with the first `i` items and a backpack capacity of `j`.

2. **Filling the DP Table**:
   - We iterate over each item from 1 to `N`.
   - For each item, we iterate over each possible capacity from 0 to `V`.
   - If the volume of the current item `v[i-1]` is less than or equal to the current capacity `j`, we have two choices:
     - Include the item and add its value to the best value we can achieve with the remaining capacity (`j - v[i-1]`).
     - Exclude the item and carry forward the best value we can achieve without it.
   - We take the maximum of these two choices.
   - If the volume of the current item is greater than the current capacity, we cannot include the item, so we carry forward the best value without it.

3. **Result**:
   - The maximum value that can be achieved with all items and full capacity `V` is stored in `dp[N][V]`.

This approach ensures that we consider all possible combinations of items and capacities, leading to an optimal solution for the 0/1 Knapsack Problem. Given the constraints, this solution will run efficiently within the time and memory limits.

*/

#endif