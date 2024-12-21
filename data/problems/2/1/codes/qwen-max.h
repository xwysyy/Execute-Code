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
        // Initialize the DP array with size V+1, all elements set to 0
        std::vector<int> dp(V + 1, 0);

        // Iterate over each item
        for (int i = 0; i < N; ++i)
        {
            // Iterate over the capacities in reverse order to avoid using an item more than once
            for (int j = V; j >= v[i]; --j)
            {
                // Update the DP array with the maximum value
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        // The result is the maximum value that can be obtained with the given capacity V
        return dp[V];
    }
};

/*

### Explanation:
1. **Initialization**:
   - We initialize a DP array `dp` of size `V + 1` with all elements set to 0. `dp[j]` will store the maximum value that can be obtained with a capacity of `j`.

2. **Iterate Over Each Item**:
   - For each item, we iterate over the capacities from `V` down to `v[i]` (the volume of the current item). This reverse iteration ensures that each item is only used once in the DP array.

3. **Update the DP Array**:
   - For each capacity `j`, we update `dp[j]` to be the maximum of its current value and the value obtained by including the current item. This is done using the formula:
     \[
     dp[j] = \max(dp[j], dp[j - v[i]] + w[i])
     \]
   - `dp[j - v[i]] + w[i]` represents the value if we include the current item in the backpack.

4. **Result**:
   - After processing all items, `dp[V]` will contain the maximum value that can be obtained with the given capacity `V`.

This approach ensures that we find the optimal solution within the given constraints. The time complexity is \(O(N \times V)\), which is efficient given the constraints.

*/

#endif