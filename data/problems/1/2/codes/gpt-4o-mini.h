#ifndef GPT-4O-MINI_H
#define GPT-4O-MINI_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve the 0/1 Knapsack problem as described, we can implement a dynamic programming approach. Below is the implementation of the `solve` function in the `Solution` class, which calculates the maximum value that can be achieved without exceeding the backpack's capacity.

*/

#include <vector>
#include <algorithm>

class Solution
{
public:
    int solve(int N, int V, std::vector<int> &v, std::vector<int> &w)
    {
        // Create a DP array to store the maximum value for each capacity std::vector<int> dp(V + 1, 0);

        // Iterate through each item for (int i = 0; i < N; i++)
        {
            // Traverse the dp array backwards to avoid overwriting values for (int j = V; j >= v[i]; j--)
            {
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        // The maximum value for the full capacity V
        return dp[V];
    }
};

/*

### Explanation of the Code:
- We create a dynamic programming array `dp` where `dp[j]` represents the maximum value that can be achieved with a backpack capacity of `j`.
- We iterate through each item and update the `dp` array from the back to the front to ensure that each item is only considered once.
- Finally, we return `dp[V]`, which contains the maximum value that can be achieved with the given backpack capacity `V`.

*/

#endif