#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

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
                    // Otherwise, take the maximum of including or not including the current item
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
1. **Initialization**: We initialize a 2D vector `dp` of size `(N+1) x (V+1)` with all elements set to 0. This table will store the maximum value that can be achieved for each subproblem.

2. **Filling the DP Table**:
   - For each item `i` from 1 to `N`:
     - For each possible knapsack capacity `j` from 0 to `V`:
       - If the volume of the current item `v[i-1]` is greater than the current capacity `j`, we cannot include this item, so we carry forward the value from the previous row (`dp[i-1][j]`).
       - Otherwise, we consider two possibilities:
         - Not including the current item: `dp[i-1][j]`
         - Including the current item: `dp[i-1][j-v[i-1]] + w[i-1]`
       - We take the maximum of these two values and store it in `dp[i][j]`.

3. **Result**: After filling the DP table, the value at `dp[N][V]` will contain the maximum value that can be achieved with the given constraints.

This approach ensures that we explore all possible combinations of items while respecting the knapsack's capacity, leading to an optimal solution.

*/

#endif