#ifndef QWEN-PLUS_H
#define QWEN-PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use a dynamic programming approach. The problem is a classic example of the 0/1 Knapsack problem where each item can be taken or not taken into the knapsack (backpack).

### Approach:
1. **Define the DP Table**:
   - Let `dp[i][j]` represent the maximum value that can be obtained using the first `i` items with a total volume not exceeding `j`.
   
2. **Initialization**:
   - Initialize `dp[0][j] = 0` for all `j`, because with 0 items, the maximum value is 0.
   
3. **DP Transition**:
   - For each item `i` and each possible volume `j`:
     - If the item `i` is not included, then `dp[i][j] = dp[i-1][j]`.
     - If the item `i` is included and its volume `v[i-1]` does not exceed `j`, then `dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1]] + w[i-1])`.

4. **Result**:
   - The answer will be in `dp[N][V]`, which represents the maximum value that can be obtained using all `N` items with a total volume not exceeding `V`.

### Code Implementation:

*/

#include <vector>
using namespace std;

class Solution {
public:
    int solve(int N, int V, vector<int>& v, vector<int>& w) {
        // Create a DP table with dimensions (N+1) x (V+1)
        vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= V; ++j) {
                // Case 1: Do not include the i-th item
                dp[i][j] = dp[i - 1][j];
                
                // Case 2: Include the i-th item if it fits
                if (v[i - 1] <= j) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
                }
            }
        }

        // The answer is in dp[N][V]
        return dp[N][V];
    }
};

/*

### Explanation:
- **Initialization**: We initialize a 2D vector `dp` of size `(N+1) x (V+1)` with all elements set to 0. This ensures that when no items are considered, the maximum value is 0.
  
- **Filling the DP Table**:
  - For each item `i` from 1 to `N`:
    - For each possible volume `j` from 0 to `V`:
      - We consider two cases:
        - Not including the current item (`dp[i-1][j]`).
        - Including the current item if it fits (`dp[i-1][j-v[i-1]] + w[i-1]`).
      - We take the maximum of these two cases.

- **Result**: After filling the DP table, `dp[N][V]` contains the maximum value that can be achieved with the given constraints.

### Example Walkthrough:
For `N = 3`, `V = 4`, `v = [4, 3, 1]`, `w = [1, 2, 1]`:
- The DP table will be filled as follows:
  - `dp[1][4] = 1` (only item 1 fits)
  - `dp[2][4] = 2` (item 2 fits better than item 1)
  - `dp[3][4] = 2` (item 3 doesn't improve the result)

Thus, the output is `2`.

This solution efficiently solves the problem within the given constraints.

*/

#endif