#ifndef QWEN-PLUS_H
#define QWEN-PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use dynamic programming to find the maximum value that can be obtained with a given capacity `V`. This is a classic 0/1 Knapsack problem where each item can either be included or excluded from the knapsack.

Here's how you can implement the solution:

*/

#include <vector>
#include <algorithm>

class Solution {
public:
    int solve(int N, int V, std::vector<int> &v, std::vector<int> &w) {
        // Create a DP table with dimensions (N+1) x (V+1)
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(V + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= V; ++j) {
                // If the current item's volume exceeds the current capacity, skip it
                if (v[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // Otherwise, take the maximum of including or excluding the current item
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
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
   - We create a 2D vector `dp` where `dp[i][j]` represents the maximum value that can be obtained using the first `i` items with a total volume not exceeding `j`.

2. **Filling the DP Table**:
   - For each item `i` and each possible volume `j`:
     - If the volume of the `i-th` item is greater than `j`, we cannot include this item, so `dp[i][j]` remains the same as `dp[i-1][j]`.
     - Otherwise, we have two choices: 
       - Exclude the `i-th` item: `dp[i-1][j]`
       - Include the `i-th` item: `dp[i-1][j - v[i-1]] + w[i-1]`
     - We choose the maximum of these two values.

3. **Result**:
   - The final result is stored in `dp[N][V]`, which gives the maximum value that can be achieved with the given capacity `V`.

This approach ensures that we consider all possible combinations of items while respecting the capacity constraint, leading to an optimal solution.

*/

#endif