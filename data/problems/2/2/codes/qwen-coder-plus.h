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
        for (int i = 0; i < N; i++)
        {
            // Traverse the DP array backwards to avoid using the same item multiple times
            for (int j = V; j >= v[i]; j--)
            {
                // Update the DP array with the maximum value obtainable
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        // The answer will be the maximum value obtainable with the full capacity V
        return dp[V];
    }
};

/*

### Explanation:
1. **Initialization**: We initialize a DP array `dp` of size `V + 1` with all elements set to 0. This array will store the maximum value that can be achieved for each possible knapsack capacity from 0 to V.

2. **Iterate Over Items**: For each item `i`, we iterate over the possible capacities `j` from `V` down to `v[i]`. This backward iteration ensures that each item is only considered once per capacity.

3. **Update DP Array**: For each capacity `j`, we update `dp[j]` to be the maximum of its current value or the value obtained by including the current item `i`. This is done using the formula:
   \[
   dp[j] = \max(dp[j], dp[j - v[i]] + w[i])
   \]
   Here, `dp[j - v[i]] + w[i]` represents the value if we include the current item `i` in the knapsack with capacity `j`.

4. **Result**: After processing all items, `dp[V]` will contain the maximum value that can be achieved with the full knapsack capacity `V`.

This approach ensures that we efficiently solve the 0/1 Knapsack problem within the given constraints.

*/

#endif