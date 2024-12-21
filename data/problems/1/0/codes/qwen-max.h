#ifndef QWEN-MAX_H
#define QWEN-MAX_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use dynamic programming. The idea is to use a 2D DP table where `dp[i][j]` represents the maximum value that can be obtained by using the first `i` items with a total volume not exceeding `j`.

Here's the implementation in C++:

*/

class Solution
{
public:
    int solve(int N, int V, std::vector<int> &v, std::vector<int> &w)
    {
        // Initialize the DP table
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(V + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j <= V; ++j)
            {
                // If the current item can be included
                if (j >= v[i - 1])
                {
                    // Choose the maximum value between including and excluding the current item
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
                }
                else
                {
                    // If the current item cannot be included, just take the value without the current item
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The answer will be in dp[N][V]
        return dp[N][V];
    }
};

/*

### Explanation:
1. **Initialization**:
   - We create a 2D DP table `dp` of size `(N+1) x (V+1)` initialized to 0. `dp[i][j]` will store the maximum value that can be obtained using the first `i` items with a total volume not exceeding `j`.

2. **Filling the DP Table**:
   - We iterate over each item from 1 to `N`.
   - For each item, we iterate over the possible volumes from 0 to `V`.
   - If the current item can be included (i.e., `j >= v[i-1]`), we update `dp[i][j]` to be the maximum of:
     - The value without including the current item: `dp[i-1][j]`.
     - The value including the current item: `dp[i-1][j - v[i-1]] + w[i-1]`.
   - If the current item cannot be included, we simply take the value without the current item: `dp[i-1][j]`.

3. **Result**:
   - The final result, which is the maximum value that can be obtained with the given constraints, is stored in `dp[N][V]`.

This approach ensures that we consider all possible combinations of items and volumes, and it runs in `O(N * V)` time, which is efficient given the constraints.

*/

#endif