#ifndef QWEN-MAX_H
#define QWEN-MAX_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use dynamic programming. The idea is to use a 1D DP array where `dp[j]` represents the maximum value that can be obtained with a backpack capacity of `j`. We will iterate through each item and update the DP array accordingly.

Here's the implementation:

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
                // Update the DP array
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
   - We initialize a DP array `dp` of size `V + 1` with all elements set to 0. This array will store the maximum value that can be obtained for each possible capacity from 0 to `V`.

2. **Iterate Over Each Item**:
   - For each item `i`, we iterate over the capacities in reverse order (from `V` to `v[i]`). This is done to ensure that each item is used at most once.

3. **Update the DP Array**:
   - For each capacity `j`, we update `dp[j]` to be the maximum of its current value and the value obtained by including the current item. The value obtained by including the current item is `dp[j - v[i]] + w[i]`.

4. **Result**:
   - After processing all items, the value `dp[V]` will contain the maximum value that can be obtained with the given capacity `V`.

This approach ensures that we consider all possible combinations of items while adhering to the constraints, and it runs efficiently within the given time and memory limits.

*/

#endif