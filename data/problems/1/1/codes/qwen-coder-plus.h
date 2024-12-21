#ifndef QWEN-CODER-PLUS_H
#define QWEN-CODER-PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use a classic dynamic programming approach known as the "0/1 Knapsack Problem". The idea is to maintain a DP table where `dp[j]` represents the maximum value that can be achieved with a backpack capacity of `j`.

Here is the implementation of the `solve` function in the `Solution` class:

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
        for (int i = 0; i < N; i++)
        {
            // Traverse the DP array backwards to avoid overwriting values
            for (int j = V; j >= v[i]; j--)
            {
                // Update the DP array with the maximum value considering the current item
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        // The maximum value for the full capacity V will be stored in dp[V]
        return dp[V];
    }
};

/*

### Explanation:
1. **Initialization**: We initialize a vector `dp` of size `V + 1` with all elements set to 0. This vector will store the maximum value that can be achieved for each possible capacity from 0 to `V`.

2. **Dynamic Programming Transition**:
   - For each item `i` (from 0 to `N-1`), we iterate over the possible capacities `j` in reverse order (from `V` to `v[i]`). This reverse iteration ensures that each item is only considered once per capacity.
   - For each capacity `j`, we update `dp[j]` to be the maximum of its current value and the value obtained by including the current item `i`. This is done using the formula: `dp[j] = max(dp[j], dp[j - v[i]] + w[i])`.

3. **Result**: After processing all items, `dp[V]` will contain the maximum value that can be achieved with the given backpack capacity `V`.

This approach ensures that we efficiently compute the solution within the given constraints. The time complexity is \(O(N \times V)\), which is feasible given the problem constraints.

*/

#endif