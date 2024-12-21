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
        std::vector<int> dp(V + 1, 0); // DP array to store maximum values

        for (int i = 0; i < N; i++)
        {
            for (int j = V; j >= v[i]; j--) // Traverse backwards to avoid overwriting
            {
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        return dp[V]; // Return the maximum value for the full capacity 
    }
};

/*

### Explanation of the Code:
- A dynamic programming array `dp` is created to store the maximum value that can be achieved for each capacity from `0` to `V`.
- The outer loop iterates through each item, while the inner loop iterates backwards through the capacities to ensure that each item is only considered once.
- The maximum value is updated based on whether including the current item yields a better value than excluding it.
- Finally, the maximum value for the full capacity `V` is returned.

*/

#endif