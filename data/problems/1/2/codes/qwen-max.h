#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution
{
public:
    int solve(int N, int V, std::vector<int> &v, std::vector<int> &w)
    {
        // Initialize a DP array with size V+1, all elements set to 0
        std::vector<int> dp(V + 1, 0);

        // Iterate over each item
        for (int i = 0; i < N; ++i)
        {
            // Iterate over the volumes from V down to v[i]
            for (int j = V; j >= v[i]; --j)
            {
                // Update the DP array to include the current item
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }

        // The answer is the maximum value that can be obtained with volume V
        return dp[V];
    }
};

/*

### Explanation:
1. **Initialization**:
   - We initialize a DP array `dp` of size \( V + 1 \) with all elements set to 0. `dp[j]` will store the maximum value that can be obtained with a volume of \( j \).

2. **Iterate Over Items**:
   - For each item \( i \) (from 0 to \( N-1 \)), we iterate over the volumes from \( V \) down to \( v[i] \). This ensures that each item is only used once and that we do not overwrite the values needed for future calculations.

3. **Update DP Array**:
   - For each volume \( j \), we update `dp[j]` to be the maximum of its current value and the value obtained by including the current item \( i \). This is done using the formula:
     \[
     dp[j] = \max(dp[j], dp[j - v[i]] + w[i])
     \]
   - Here, `dp[j - v[i]] + w[i]` represents the value obtained by including the current item \( i \) in the knapsack, and `dp[j]` represents the value without including the current item.

4. **Result**:
   - After processing all items, the value at `dp[V]` will be the maximum value that can be obtained with a volume of \( V \).

This approach ensures that we find the optimal solution within the given constraints. The time complexity is \( O(N \times V) \), which is efficient given the constraints.

*/

#endif