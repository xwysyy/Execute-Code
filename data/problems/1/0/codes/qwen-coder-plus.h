#ifndef QWEN-CODER-PLUS_H
#define QWEN-CODER-PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use a dynamic programming approach known as the "0/1 Knapsack Problem" solution. The idea is to maintain a DP table where `dp[j]` represents the maximum value that can be achieved with a knapsack capacity of `j`.

Here's the implementation of the `solve` function in the `Solution` class:

*/

#include <vector>
#include <algorithm>

class Solution
{
public:
    int solve(int N, int V, std::vector<int> &v, std::vector<int> &w)
    {
        // Create a DP array to store the maximum value for each capacity from 0 to V
        std::vector<int> dp(V + 1, 0);

        // Iterate over each item
        for (int i = 0; i < N; ++i)
        {
            // Traverse the DP array backwards to avoid overwriting values that we still need to use
            for (int j = V; j >= v[i]; --j)
            {
                // Update the DP value for the current capacity
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        // The answer is the maximum value that can be achieved with the full capacity V
        return dp[V];
    }
};

/*

### Explanation:
1. **Initialization**: We initialize a vector `dp` of size `V + 1` with all elements set to 0. This vector will store the maximum value achievable for each capacity from 0 to V.
2. **Iterate Over Items**: For each item, we iterate over the possible capacities in reverse order (from `V` down to `v[i]`). This reverse iteration ensures that each item is only considered once per capacity.
3. **Update DP Table**: For each capacity `j`, we update `dp[j]` to be the maximum of its current value and the value obtained by including the current item (`dp[j - v[i]] + w[i]`).
4. **Result**: After processing all items, `dp[V]` contains the maximum value that can be achieved with the full capacity `V`.

This approach ensures that we efficiently compute the maximum value for the knapsack problem within the given constraints.

*/

#endif