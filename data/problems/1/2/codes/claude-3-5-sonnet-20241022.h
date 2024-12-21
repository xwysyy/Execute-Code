#ifndef CLAUDE-3-5-SONNET-20241022_H
#define CLAUDE-3-5-SONNET-20241022_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use dynamic programming. This is a classic 0/1 knapsack problem. Here's the implementation of the `solve` function:

*/

class Solution
{
public:
    int solve(int N, int V, std::vector<int>& v, std::vector<int>& w)
    {
        std::vector<int> dp(V + 1, 0);
        
        for (int i = 0; i < N; i++)
        {
            for (int j = V; j >= v[i]; j--)
            {
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        return dp[V];
    }
};

/*

This solution uses a 1D dynamic programming approach to solve the 0/1 knapsack problem. Here's how it works:

1. We create a `dp` vector of size `V + 1`, initialized with zeros. `dp[j]` represents the maximum value that can be achieved with a knapsack of capacity `j`.

2. We iterate through each item (outer loop with index `i`).

3. For each item, we iterate backwards through the possible capacities from `V` to `v[i]` (inner loop with index `j`). We iterate backwards to ensure that we don't use the same item multiple times.

4. For each capacity `j`, we have two choices:
   - Don't include the current item: the value remains `dp[j]`
   - Include the current item: the value becomes `dp[j - v[i]] + w[i]`
   We take the maximum of these two choices.

5. After considering all items for all capacities, `dp[V]` gives us the maximum value that can be achieved with the given knapsack capacity.

This solution satisfies the constraints:
- It works for the given ranges of N, V, v[i], and w[i].
- The time complexity is O(N*V), which should be within the 1000 ms time limit for the given constraints.
- The space complexity is O(V), which should be within the 64 KB memory limit.

*/

#endif