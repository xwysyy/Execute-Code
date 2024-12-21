#ifndef QWEN-CODER-PLUS_H
#define QWEN-CODER-PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use a dynamic programming approach known as the "0/1 Knapsack Problem". The idea is to create a 2D DP table where `dp[i][j]` represents the maximum value that can be obtained using the first `i` items with a total volume not exceeding `j`.

Here's how you can implement the `solve` function in the `Solution` class:

*/

#include <vector>
#include <algorithm>

class Solution
{
public:
    int solve(int N, int V, std::vector<int> &v, std::vector<int> &w)
    {
        // Create a 2D DP table with (N+1) x (V+1) dimensions
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(V + 1, 0));

        // Iterate over each item
        for (int i = 1; i <= N; i++)
        {
            // Iterate over each possible volume capacity
            for (int j = 0; j <= V; j++)
            {
                // If the current item's volume is less than or equal to the current capacity
                if (v[i - 1] <= j)
                {
                    // We have two choices: include the item or exclude it
                    // Take the maximum value between including and excluding the item
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
                }
                else
                {
                    // If we cannot include the item, take the value without it
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The answer will be in dp[N][V], which represents the maximum value using all items with capacity V
        return dp[N][V];
    }
};

/*

### Explanation:
1. **Initialization**: We initialize a 2D vector `dp` of size `(N+1) x (V+1)` with all elements set to 0. This table will store the maximum value that can be achieved with the first `i` items and a knapsack capacity of `j`.

2. **Filling the DP Table**:
   - We iterate over each item from 1 to `N`.
   - For each item, we iterate over each possible volume capacity from 0 to `V`.
   - If the volume of the current item (`v[i-1]`) is less than or equal to the current capacity `j`, we have two choices:
     - **Include the item**: The value would be `dp[i-1][j-v[i-1]] + w[i-1]`, which means we add the value of the current item to the maximum value obtainable with the remaining capacity (`j - v[i-1]`).
     - **Exclude the item**: The value remains `dp[i-1][j]`.
   - We take the maximum of these two choices.
   - If the volume of the current item is greater than the current capacity, we cannot include the item, so the value remains `dp[i-1][j]`.

3. **Result**: The maximum value that can be obtained with all items and a knapsack capacity of `V` is stored in `dp[N][V]`.

This approach ensures that we consider all possible combinations of items and capacities, leading to an optimal solution. The time complexity is \(O(N \times V)\), which is efficient given the constraints.

*/

#endif