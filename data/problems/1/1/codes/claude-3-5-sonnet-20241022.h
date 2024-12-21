#ifndef CLAUDE-3-5-SONNET-20241022_H
#define CLAUDE-3-5-SONNET-20241022_H
#include <bits/stdc++.h>
using namespace std;

/*

This is a classic 0/1 knapsack problem. Here's the solution using dynamic programming:

*/

class Solution {
public:
    int solve(int N, int V, std::vector<int>& v, std::vector<int>& w) {
        // Create a DP table
        std::vector<int> dp(V + 1, 0);
        
        // For each item
        for (int i = 0; i < N; i++) {
            // For each capacity from V down to the volume of current item
            for (int j = V; j >= v[i]; j--) {
                // Maximum of either not taking the item (dp[j])
                // or taking the item (dp[j-v[i]] + w[i])
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        return dp[V];
    }
};

/*

This solution:

1. Creates a 1D DP array where dp[j] represents the maximum value that can be achieved with capacity j.

2. For each item i and each capacity j:
   - We can either not include the item (keep dp[j] as is)
   - Or include the item (add w[i] to the value achievable with remaining capacity j-v[i])
   - We take the maximum of these two choices

3. We iterate through capacities in reverse order to ensure we don't use the same item multiple times.

4. Finally returns dp[V] which contains the maximum value achievable with capacity V.

Time Complexity: O(N*V)
Space Complexity: O(V)

The solution handles all the constraints:
- Works for 0 < N, V, v[i], w[i] ≤ 100
- Memory usage is minimal (only one array of size V+1)
- Time complexity is efficient enough for the given constraints

For the example input:
N = 3, V = 4, v = [4, 3, 1], w = [1, 2, 1]
The function returns 2, which is correct because we can take the second item (volume=3, value=2) and store it in the backpack of capacity 4.

*/

#endif