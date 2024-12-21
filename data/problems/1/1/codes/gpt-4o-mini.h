#ifndef GPT-4O-MINI_H
#define GPT-4O-MINI_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve the 0/1 Knapsack problem as described, we can implement a dynamic programming approach. Below is the updated code for the `solve` function in the `Solution` class, which calculates the maximum value that can be achieved without exceeding the backpack's capacity.

*/

#include <vector>
#include <algorithm>

class Solution
{
public:
    int solve(int N, int V, std::vector<int> &v, std::vector<int> &w)
    {
        std::vector<int> dp(V + 1, 0); // DP array to store maximum values

        for (int i = 0; i < N; i++)
        {
            for (int j = V; j >= v[i]; j--) // Traverse backwards to avoid overwriting
            {
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        return dp[V]; // Maximum value for the full capacity }
};

/*

### Explanation of the Updates:
- **Dynamic Programming Array**: We use a 1D array `dp` to store the maximum value for each capacity from `0` to `V`.
- **Nested Loops**: The outer loop iterates through each item, and the inner loop iterates backwards through the capacities to ensure that each item is only considered once.
- **Max Value Calculation**: For each item, we update the `dp` array to reflect the maximum value achievable for each capacity.

This implementation efficiently computes the maximum value that can be carried in the backpack while adhering to the constraints provided.

*/

#endif