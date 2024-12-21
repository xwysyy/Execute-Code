#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution {
public:
    int solve(int N, int V, vector<int>& v, vector<int>& w) {
        // dp[i] represents the maximum value that can be achieved with capacity i
        vector<int> dp(V + 1, 0);
        
        // For each item
        for (int i = 0; i < N; i++) {
            // Process from right to left to avoid using same item multiple times
            for (int j = V; j >= v[i]; j--) {
                // For each capacity j, we can either:
                // 1. Not include the current item: dp[j]
                // 2. Include the current item: dp[j-v[i]] + w[i]
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        return dp[V];
    }
};

/*

This solution:

1. Creates a DP array where `dp[i]` represents the maximum value that can be achieved with capacity i.

2. For each item, we iterate through all possible capacities from V down to the volume of current item.

3. For each capacity j, we have two choices:
   - Don't take the current item: value stays as dp[j]
   - Take the current item: add current item's value (w[i]) to the maximum value achievable with remaining capacity (dp[j-v[i]])

4. We take the maximum of these two choices.

5. We iterate from right to left to ensure each item is used at most once.

Time Complexity: O(N*V)
Space Complexity: O(V)

For the example:
Input: N = 3, V = 4, v = [4, 3, 1], w = [1, 2, 1]

The algorithm will process each item and find that:
- We can either take item 2 (value=2, volume=3)
- Or take item 3 (value=1, volume=1)
- Can't take item 1 as its volume (4) exceeds capacity

The maximum achievable value is 2, which comes from taking item 2 alone.

*/

#endif