#ifndef GPT-4O-MINI_H
#define GPT-4O-MINI_H
#include <bits/stdc++.h>
using namespace std;

/*

Here’s the implementation of the `solve` function in the `Solution` class to solve the 0/1 Knapsack problem based on your requirements:

*/

#include <vector>
#include <algorithm>

class Solution
{
public:
    int solve(int N, int V, std::vector<int> &v, std::vector<int> &w)
    {
        // Create a DP array to store the maximum value for each capacity
        std::vector<int> dp(V + 1, 0);
        
        // Iterate through each item 
        for (int i = 0; i < N; i++)
        {
            // Traverse the dp array backwards
            for (int j = V; j >= v[i]; j--)
            {
                // Update the dp value for the current capacity
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        // The maximum value for the full capacity V return dp[V];
    }
};

/*

### Explanation of the Code:
- A dynamic programming array `dp` is created to store the maximum value that can be achieved for each capacity from `0` to `V`.
- For each item, we iterate through the capacities in reverse to ensure that each item is only considered once.
- The maximum value is updated based on whether including the current item yields a higher value than excluding it.
- Finally, the maximum value for the backpack's full capacity `V` is returned.

*/

#endif