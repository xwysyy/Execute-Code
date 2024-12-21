#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution {
public:
    int solve(int N, int V, std::vector<int>& v, std::vector<int>& w) {
        // Create a 2D DP table
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(V + 1, 0));
        
        // Fill the DP table
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= V; j++) {
                // If current item volume exceeds current capacity, skip it
                if (v[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    // Max of two choices:
                    // 1. Not including current item
                    // 2. Including current item
                    dp[i][j] = std::max(
                        dp[i-1][j],  // Not including current item
                        dp[i-1][j-v[i-1]] + w[i-1]  // Including current item
                    );
                }
            }
        }
        
        // Return maximum value possible
        return dp[N][V];
    }
};

/*

This solution uses the classic 0/1 knapsack dynamic programming approach:

1. Create a 2D DP table where:
   - Rows represent items (0 to N)
   - Columns represent backpack capacities (0 to V)

2. The entry `dp[i][j]` represents the maximum value that can be achieved 
   - Using first `i` items
   - With a backpack capacity of `j`

3. For each item, we have two choices:
   - Don't include the item: `dp[i-1][j]`
   - Include the item if possible: `dp[i-1][j-v[i-1]] + w[i-1]`

4. We take the maximum of these two choices

5. Time Complexity: O(N*V)
6. Space Complexity: O(N*V)

For the given example:
- N = 3
- V = 4
- v = [4, 3, 1]
- w = [1, 2, 1]

The function will return 2, which could be achieved by selecting the second and third items 
(volume 3 + 1 = 4, total value 2 + 1 = 3).

This solution handles the constraints:
- 0 < N, V, v[i], w[i] ≤ 100
- Each item can only be used once
- Maximize total value while keeping total volume ≤ V

*/

#endif