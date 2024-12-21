#ifndef DEEPSEEK-CHAT_H
#define DEEPSEEK-CHAT_H
#include <bits/stdc++.h>
using namespace std;

/*

This problem is a classic example of the 0/1 Knapsack problem, where you need to maximize the value of items without exceeding the backpack's capacity. We can solve this using dynamic programming.

Here's the implementation of the `solve` function:

*/

#include <vector>
#include <algorithm>

class Solution {
public:
    int solve(int N, int V, std::vector<int>& v, std::vector<int>& w) {
        // Create a DP array where dp[j] represents the maximum value with capacity j
        std::vector<int> dp(V + 1, 0);

        // Iterate over each item
        for (int i = 0; i < N; ++i) {
            // Update the DP array in reverse to prevent using the same item multiple times
            for (int j = V; j >= v[i]; --j) {
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        // The maximum value will be in dp[V]
        return dp[V];
    }
};

/*

### Explanation:
1. **DP Array Initialization**: We initialize a DP array `dp` of size `V + 1` with all elements set to 0. `dp[j]` will store the maximum value that can be achieved with a backpack capacity of `j`.

2. **Iterating Over Items**: We iterate over each item. For each item, we update the DP array in reverse order (from `V` to `v[i]`). This ensures that each item is only used once.

3. **Updating DP Array**: For each capacity `j`, we decide whether to include the current item or not. If we include the item, the value becomes `dp[j - v[i]] + w[i]`. We take the maximum of this value and the current value `dp[j]`.

4. **Result**: After processing all items, the maximum value that can be achieved with the backpack capacity `V` is stored in `dp[V]`.

### Example Walkthrough:
For the input `N = 3, V = 4, v = [4, 3, 1], w = [1, 2, 1]`:
- Initialize `dp = [0, 0, 0, 0, 0]`.
- Process the first item (volume 4, value 1):
  - Update `dp[4] = max(0, 0 + 1) = 1`.
- Process the second item (volume 3, value 2):
  - Update `dp[3] = max(0, 0 + 2) = 2`.
  - Update `dp[4] = max(1, 0 + 2) = 2`.
- Process the third item (volume 1, value 1):
  - Update `dp[1] = max(0, 0 + 1) = 1`.
  - Update `dp[2] = max(0, 1 + 1) = 2`.
  - Update `dp[3] = max(2, 1 + 1) = 2`.
  - Update `dp[4] = max(2, 1 + 1) = 2`.

The final `dp` array is `[0, 1, 2, 2, 2]`, and the maximum value is `dp[4] = 2`.

This solution efficiently solves the problem within the given constraints.

*/

#endif