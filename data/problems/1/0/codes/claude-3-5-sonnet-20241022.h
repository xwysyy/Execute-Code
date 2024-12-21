#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution
{
public:
    int solve(int N, int V, std::vector<int>& v, std::vector<int>& w)
    {
        std::vector<int> dp(V + 1, 0);
        
        for (int i = 0; i < N; i++)
        {
            for (int j = V; j >= v[i]; j--)
            {
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        return dp[V];
    }
};

/*

This solution uses a 1D dynamic programming array to solve the problem. Here's how it works:

1. We create a DP array `dp` of size `V + 1`, initialized with zeros. `dp[j]` represents the maximum value that can be achieved with a knapsack of capacity `j`.

2. We iterate through each item (outer loop with index `i`).

3. For each item, we iterate backwards through the capacities from `V` to `v[i]` (inner loop with index `j`). We iterate backwards to ensure that we don't use the same item multiple times.

4. For each capacity `j`, we have two choices:
   - Don't include the current item: value remains `dp[j]`
   - Include the current item: value becomes `dp[j - v[i]] + w[i]`
   We take the maximum of these two choices.

5. After considering all items for all capacities, `dp[V]` gives us the maximum value achievable with the given knapsack capacity.

This solution has a time complexity of O(N*V) and a space complexity of O(V), which should be within the given constraints.

*/

#endif