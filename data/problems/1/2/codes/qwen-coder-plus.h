#ifndef QWEN-CODER-PLUS_H
#define QWEN-CODER-PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use a classic dynamic programming approach known as the "0/1 Knapsack Problem." The idea is to maintain a DP table where `dp[j]` represents the maximum value that can be achieved with a knapsack capacity of `j`.

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
            // Traverse the DP array backwards to avoid overwriting values
            for (int j = V; j >= v[i]; --j)
            {
                // Update the DP array with the maximum value achievable
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        // The maximum value that can be achieved with capacity V is stored in dp[V]
        return dp[V];
    }
};

/*

### Explanation:
1. **Initialization**: We initialize a DP array `dp` of size `V + 1` with all elements set to 0. This array will store the maximum value that can be achieved for each possible knapsack capacity from 0 to `V`.

2. **Iterate Over Items**: For each item `i`, we consider its volume `v[i]` and value `w[i]`.

3. **Update DP Array**: We iterate over the DP array from the back (`j = V` to `j = v[i]`) to ensure that each item is only considered once per capacity. For each capacity `j`, we update `dp[j]` to be the maximum of its current value or the value obtained by including the current item (`dp[j - v[i]] + w[i]`).

4. **Result**: After processing all items, the maximum value that can be achieved with the full knapsack capacity `V` is stored in `dp[V]`.

This approach ensures that we efficiently compute the solution within the given constraints.

*/

#endif