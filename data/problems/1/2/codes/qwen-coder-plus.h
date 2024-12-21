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
        // Create a DP array to store the maximum value for each capacity from 0 to V
        std::vector<int> dp(V + 1, 0);

        // Iterate over each item
        for (int i = 0; i < N; ++i)
        {
            // Traverse the DP array backwards to avoid overwriting values that we still need to use
            for (int j = V; j >= v[i]; --j)
            {
                // Update the DP array with the maximum value achievable by including the current item
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        // The answer will be the maximum value achievable with the full capacity V
        return dp[V];
    }
};

/*

### Explanation:

1. **Initialization**:
   - We initialize a vector `dp` of size `V + 1` with all elements set to 0. This vector will store the maximum value that can be achieved for each possible capacity from 0 to `V`.

2. **Iterate Over Items**:
   - For each item `i`, we consider whether to include it in the knapsack or not.
   - We iterate over the capacities from `V` down to `v[i]`. This reverse iteration ensures that each item is only considered once per capacity.

3. **Update DP Table**:
   - For each capacity `j`, we update `dp[j]` to be the maximum of its current value and the value obtained by including the current item `i`. This is done using the formula:
     \[
     dp[j] = \max(dp[j], dp[j - v[i]] + w[i])
     \]
   - Here, `dp[j - v[i]]` represents the maximum value achievable with the remaining capacity after including the current item, and `w[i]` is the value of the current item.

4. **Result**:
   - After processing all items, `dp[V]` will contain the maximum value that can be achieved with the full capacity `V`.

This approach ensures that we efficiently compute the solution within the given constraints.

*/

#endif