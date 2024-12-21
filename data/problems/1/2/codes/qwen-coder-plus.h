#ifndef QWEN-CODER-PLUS_H
#define QWEN-CODER-PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use a dynamic programming approach known as the "0/1 Knapsack Problem" solution. This problem involves determining the maximum value that can be obtained by selecting a subset of items such that the total weight (or volume, in this case) does not exceed the given capacity.

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
        for (int i = 0; i < N; i++)
        {
            // Traverse the dp array backwards to avoid using the same item multiple times
            for (int j = V; j >= v[i]; j--)
            {
                // Update the dp array with the maximum value obtainable
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        // The answer will be the maximum value obtainable with the full capacity V
        return dp[V];
    }
};

/*

### Explanation:

1. **Dynamic Programming Array (`dp`)**:
   - We use a 1D array `dp` where `dp[j]` represents the maximum value that can be obtained with a knapsack capacity of `j`.

2. **Initialization**:
   - Initialize the `dp` array with zeros. This means initially, with zero capacity, the maximum value is zero.

3. **Iterate Over Items**:
   - For each item `i`, we consider whether to include it in the knapsack or not.

4. **Update DP Array**:
   - We iterate over the `dp` array in reverse order (from `V` to `v[i]`). This ensures that each item is only considered once per capacity.
   - For each capacity `j`, we update `dp[j]` to be the maximum of its current value or the value obtained by including the current item `i` (which is `dp[j - v[i]] + w[i]`).

5. **Result**:
   - After processing all items, `dp[V]` contains the maximum value that can be obtained with the full capacity `V`.

This approach ensures that we efficiently compute the maximum value without exceeding the given volume constraint, adhering to the time and memory constraints provided.

*/

#endif