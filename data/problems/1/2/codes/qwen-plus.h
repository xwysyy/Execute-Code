#ifndef QWEN-PLUS_H
#define QWEN-PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use a dynamic programming approach known as the 0/1 Knapsack problem. The idea is to create a DP table where `dp[i][j]` represents the maximum value that can be obtained with the first `i` items and a knapsack capacity of `j`.

Here's how you can implement it:

*/

#include <vector>
#include <algorithm>

class Solution {
public:
    int solve(int N, int V, std::vector<int>& v, std::vector<int>& w) {
        // Create a DP table with dimensions (N+1) x (V+1)
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(V + 1, 0));
        
        // Fill the DP table
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= V; ++j) {
                // If the current item's volume is greater than the current capacity, skip it
                if (v[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // Otherwise, take the maximum value between not taking the item and taking the item
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
   - We initialize a 2D vector `dp` of size `(N+1) x (V+1)` with all elements set to 0. This table will store the maximum value that can be obtained for each combination of items and capacities.

2. **Filling the DP Table**:
   - For each item `i` from 1 to `N`, and for each possible capacity `j` from 0 to `V`:
     - If the volume of the current item `v[i-1]` is greater than the current capacity `j`, we cannot include this item, so we carry forward the value from the previous row (`dp[i-1][j]`).
     - Otherwise, we have two choices:
       - Not include the current item: `dp[i-1][j]`
       - Include the current item: `dp[i-1][j - v[i-1]] + w[i-1]`
     - We choose the maximum of these two values.

3. **Result**:
   - The final result, which is the maximum value that can be obtained with all `N` items and a knapsack capacity of `V`, is stored in `dp[N][V]`.

This solution ensures that we explore all possible combinations of items while adhering to the knapsack's capacity constraint, ultimately finding the maximum value.

*/

#endif