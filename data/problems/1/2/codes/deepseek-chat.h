#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution {
public:
    int solve(int N, int V, std::vector<int>& v, std::vector<int>& w) {
        // Create a DP array where dp[j] will store the maximum value for capacity j
        std::vector<int> dp(V + 1, 0);

        // Iterate over each item
        for (int i = 0; i < N; ++i) {
            // Iterate over the capacity from V down to v[i]
            for (int j = V; j >= v[i]; --j) {
                // Update dp[j] to be the maximum of its current value or the value
                // obtained by including the i-th item
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        // The answer will be in dp[V], which is the maximum value for the given capacity V
        return dp[V];
    }
};

/*

### Explanation:

1. **Initialization**: We initialize a DP array `dp` of size `V + 1` with all elements set to 0. `dp[j]` will store the maximum value that can be obtained with a backpack capacity of `j`.

2. **DP Table Update**:
   - For each item `i`, we iterate over the capacity `j` from `V` down to `v[i]`. This ensures that each item is considered only once (0/1 property).
   - For each capacity `j`, we update `dp[j]` to be the maximum of its current value or the value obtained by including the `i-th` item. This is done using the formula `dp[j] = max(dp[j], dp[j - v[i]] + w[i])`.

3. **Result**: The final result, which is the maximum value that can be obtained with the backpack capacity `V`, is stored in `dp[V]`.

### Example Walkthrough:

For the input:
- `N = 3`
- `V = 4`
- `v = [4, 3, 1]`
- `w = [1, 2, 1]`

The DP table will be updated as follows:

- Initially, `dp = [0, 0, 0, 0, 0]`
- After processing the first item (volume 4, value 1):
  - `dp = [0, 0, 0, 0, 1]`
- After processing the second item (volume 3, value 2):
  - `dp = [0, 0, 0, 2, 2]`
- After processing the third item (volume 1, value 1):
  - `dp = [0, 1, 1, 2, 3]`

The final value in `dp[4]` is `3`, which is the maximum value that can be obtained with a backpack capacity of 4.

However, in the example provided, the expected output is `2`. This discrepancy suggests that there might be a mistake in the example or the constraints. The correct maximum value for the given input should be `3`, as shown in the DP table.

*/

#endif