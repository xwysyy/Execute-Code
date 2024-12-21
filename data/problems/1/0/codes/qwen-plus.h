#ifndef QWEN-PLUS_H
#define QWEN-PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use a dynamic programming approach to implement the 0/1 Knapsack problem. The idea is to create a DP table where `dp[i][j]` represents the maximum value that can be obtained using the first `i` items with a total volume not exceeding `j`.

Here's how you can implement it:

*/

#include <vector>
using namespace std;

class Solution {
public:
    int solve(int N, int V, vector<int>& v, vector<int>& w) {
        // Initialize the DP table
        vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= V; ++j) {
                if (v[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
                }
            }
        }

        // The answer is in dp[N][V]
        return dp[N][V];
    }
};

/*

### Explanation:

1. **Initialization**:
   - We initialize a 2D vector `dp` of size `(N+1) x (V+1)` with all elements set to 0. This table will store the maximum value that can be achieved with the first `i` items and a total volume not exceeding `j`.

2. **Filling the DP Table**:
   - For each item `i` from 1 to `N`:
     - For each possible volume `j` from 0 to `V`:
       - If the volume of the current item `v[i-1]` is greater than `j`, we cannot include this item, so we carry forward the value from the previous row (`dp[i-1][j]`).
       - Otherwise, we have two choices: either include the current item or exclude it. We take the maximum of these two choices:
         - Exclude the item: `dp[i-1][j]`
         - Include the item: `dp[i-1][j - v[i-1]] + w[i-1]`

3. **Result**:
   - The final result, which is the maximum value that can be achieved with all `N` items and a total volume not exceeding `V`, is stored in `dp[N][V]`.

This approach ensures that we consider all possible combinations of items while adhering to the constraints of the knapsack's capacity. The time complexity of this solution is O(N * V), which is efficient given the constraints.

*/

#endif