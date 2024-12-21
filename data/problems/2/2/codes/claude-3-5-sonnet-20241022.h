#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution {
public:
    int solve(int N, int V, std::vector<int>& v, std::vector<int>& w) {
        // Create a DP array to store maximum value for each capacity
        std::vector<int> dp(V + 1, 0);
        
        // For each item
        for (int i = 0; i < N; i++) {
            // Go through all capacities from V down to v[i]
            for (int j = V; j >= v[i]; j--) {
                // Maximum of not taking the item (dp[j])
                // or taking the item (dp[j-v[i]] + w[i])
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        return dp[V];
    }
};

/*

This solution:

1. Uses a 1D DP array where dp[j] represents the maximum value that can be achieved with capacity j.

2. For each item i:
   - Goes through all possible capacities from V down to v[i]
   - For each capacity j, decides whether to include the current item or not
   - Updates dp[j] with the maximum value possible

3. Returns dp[V] which contains the maximum value possible for the given capacity V.

Time Complexity: O(N*V)
Space Complexity: O(V)

The solution handles all the constraints:
- Works for N, V, v[i], w[i] ≤ 1000
- Memory usage is optimal as we use a 1D array instead of 2D
- Time complexity is within the limit

For the example:
Input: N = 3, V = 4, v = [4, 3, 1], w = [1, 2, 1]
- The optimal solution is to take item 2 (volume=3, value=2)
- Output: 2

The algorithm will give the correct maximum value while ensuring the total volume doesn't exceed the backpack's capacity.

*/

#endif