#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution {
public:
    int solve(int N, int V, std::vector<int>& v, std::vector<int>& w) {
        // Initialize the DP table
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(V + 1, 0));

        // Build the DP table
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= V; ++j) {
                // If the current item can fit in the backpack
                if (j >= v[i - 1]) {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
                } else {
                    // If the current item cannot fit, carry forward the previous value
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The maximum value is in dp[N][V]
        return dp[N][V];
    }
};

/*

### Explanation:
- **Initialization**: We create a DP table `dp` with `N+1` rows and `V+1` columns, all initialized to 0.
- **DP Table Construction**:
  - We iterate through each item (`i` from 1 to N).
  - For each item, we check all possible capacities (`j` from 0 to V).
  - If the current capacity `j` is greater than or equal to the volume of the current item `v[i-1]`, we consider two options:
    1. Not including the item: `dp[i-1][j]`
    2. Including the item: `dp[i-1][j - v[i-1]] + w[i-1]`
    - We take the maximum of these two options.
  - If the current capacity `j` is less than the volume of the current item, we cannot include the item, so we carry forward the value from the previous item.
- **Result**: The maximum value that can be obtained with all `N` items and a backpack capacity of `V` is stored in `dp[N][V]`.

This approach ensures that we consider all possible combinations of items and capacities to find the maximum value that can be achieved without exceeding the backpack's capacity.

*/

#endif