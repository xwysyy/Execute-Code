#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution
{
public:
    int solve(int N, int V, std::vector<int> &v, std::vector<int> &w)
    {
        // Initialize the dp array with size V+1, all set to 0
        std::vector<int> dp(V + 1, 0);

        // Iterate over each item
        for (int i = 0; i < N; ++i)
        {
            // Iterate over the capacities in reverse order to avoid using the same item multiple times
            for (int j = V; j >= v[i]; --j)
            {
                // Update the dp value for capacity j
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        // The answer is the maximum value for the full capacity V
        return dp[V];
    }
};

/*

### Explanation:
1. **Initialization**:
   - We initialize a `dp` array of size `V + 1` with all elements set to 0. This array will store the maximum value that can be obtained for each capacity from 0 to `V`.

2. **Iterate Over Each Item**:
   - For each item `i`, we iterate over the capacities from `V` down to `v[i]` (in reverse order). This ensures that each item is used at most once.

3. **Update the DP Array**:
   - For each capacity `j`, we update `dp[j]` to be the maximum of its current value and the value obtained by including the current item `i` (i.e., `dp[j - v[i]] + w[i]`).

4. **Result**:
   - After processing all items, the value `dp[V]` will contain the maximum value that can be obtained with a backpack capacity of `V`.

This approach ensures that we consider all possible combinations of items while keeping the total volume within the backpack's capacity. The time complexity is `O(N * V)`, which is efficient given the constraints.

*/

#endif