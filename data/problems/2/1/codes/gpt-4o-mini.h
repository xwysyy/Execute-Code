#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

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
                // Update the maximum value for the current capacity 
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
- We iterate through each item and update the `dp` array in reverse to ensure that each item is only considered once.
- Finally, we return `dp[V]`, which contains the maximum value that can be achieved with the given backpack capacity.

*/

#endif