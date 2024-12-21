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
        // Create a 2D DP array with (N+1) x (V+1) dimensions
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(V + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j <= V; ++j)
            {
                if (v[i - 1] <= j)
                {
                    dp[i][j] = std::max(dp[i - 1][j], w[i - 1] + dp[i - 1][j - v[i - 1]]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The answer is in dp[N][V]
        return dp[N][V];
    }
};

/*

### Explanation:
- We initialize a 2D vector `dp` of size `(N+1) x (V+1)` with all elements set to 0.
- We iterate over each item from 1 to N.
- For each item, we iterate over each possible volume from 0 to V.
- If the volume of the current item `v[i-1]` is less than or equal to the current capacity `j`, we decide whether to include the item or not by taking the maximum of including and excluding it.
- If the volume of the current item `v[i-1]` is greater than the current capacity `j`, we cannot include the item, so we just carry forward the value from the previous item `dp[i-1][j]`.
- Finally, `dp[N][V]` contains the maximum value that can be achieved with the given constraints.

This solution has a time complexity of \(O(N \times V)\) and a space complexity of \(O(N \times V)\), which is efficient given the problem constraints.

*/

#endif