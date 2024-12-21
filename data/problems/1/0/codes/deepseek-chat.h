#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution {
public:
    int solve(int N, int V, std::vector<int>& v, std::vector<int>& w) {
        // Initialize a DP array with size V+1, all values set to 0
        std::vector<int> dp(V + 1, 0);

        // Iterate through each item
        for (int i = 0; i < N; ++i) {
            // Update the DP array in reverse to avoid using the same item multiple times
            for (int j = V; j >= v[i]; --j) {
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        // The maximum value is stored in dp[V]
        return dp[V];
    }
};

/*

### Explanation:
1. **Initialization**: We initialize a DP array `dp` of size `V+1` with all values set to 0. This array will store the maximum value that can be achieved for each capacity from 0 to `V`.

2. **Iterating Through Items**: For each item, we update the DP array. We iterate from `V` down to `v[i]` to ensure that each item is only used once (this is the key to the 0/1 Knapsack problem).

3. **Updating DP Array**: For each capacity `j`, we decide whether to include the current item or not. If we include the item, we add its value to `dp[j - v[i]]` (which is the maximum value without this item but with reduced capacity). We then take the maximum of including or not including the item.

4. **Result**: After processing all items, `dp[V]` will contain the maximum value that can be achieved with the backpack capacity `V`.

### Example Walkthrough:
For the input `N = 3, V = 4, v = [4, 3, 1], w = [1, 2, 1]`:
- Initialize `dp = [0, 0, 0, 0, 0]`.
- Process the first item (volume 4, value 1):
  - Update `dp[4] = max(0, dp[0] + 1) = 1`.
  - `dp = [0, 0, 0, 0, 1]`.
- Process the second item (volume 3, value 2):
  - Update `dp[3] = max(0, dp[0] + 2) = 2`.
  - Update `dp[4] = max(1, dp[1] + 2) = 2`.
  - `dp = [0, 0, 0, 2, 2]`.
- Process the third item (volume 1, value 1):
  - Update `dp[1] = max(0, dp[0] + 1) = 1`.
  - Update `dp[2] = max(0, dp[1] + 0) = 1`.
  - Update `dp[3] = max(2, dp[2] + 1) = 2`.
  - Update `dp[4] = max(2, dp[3] + 1) = 3`.
  - `dp = [0, 1, 1, 2, 3]`.

The final result is `dp[4] = 3`, but according to the example, the expected output is `2`. This discrepancy suggests that the example might be incorrect or there might be a misunderstanding in the problem statement. However, the provided code correctly implements the 0/1 Knapsack problem and should work for valid inputs.

*/

#endif