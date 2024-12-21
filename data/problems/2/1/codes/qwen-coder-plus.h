#ifndef QWEN_CODER_PLUS_H
#define QWEN_CODER_PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution
{
public:
    int solve(int N, int V, std::vector<int> &v, std::vector<int> &w)
    {
        // Initialize the DP array with 0s
        std::vector<int> dp(V + 1, 0);
        
        // Iterate through each item
        for (int i = 0; i < N; ++i)
        {
            // Iterate backward through the DP array
            for (int j = V; j >= v[i]; --j)
            {
                // Update the DP array
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        // The maximum value that can be achieved with capacity V is stored in dp[V]
        return dp[V];
    }
};

/*

### Explanation:

- **Initialization**: We initialize a vector `dp` of size `V + 1` with all elements set to 0. This vector will store the maximum value that can be achieved for each possible capacity from 0 to `V`.

- **Outer Loop (Items)**: We loop through each item. For each item, we consider whether to include it in the knapsack or not.

- **Inner Loop (Capacity)**: We loop backward from the maximum capacity `V` down to the volume of the current item `v[i]`. This backward iteration ensures that each item is only considered once per capacity.

- **DP Update**: For each capacity `j`, we update `dp[j]` to be the maximum of its current value and the value obtained by including the current item (`dp[j - v[i]] + w[i]`).

- **Result**: After processing all items, `dp[V]` will contain the maximum value that can be achieved with a knapsack capacity of `V`.

This approach ensures that we efficiently compute the solution within the given constraints.

*/

#endif