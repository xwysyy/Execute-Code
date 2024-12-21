#ifndef QWEN-PLUS_H
#define QWEN-PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

To solve this problem, we can use dynamic programming to find the maximum value that can be obtained without exceeding the backpack's capacity. This is a classic 0/1 Knapsack problem.

Here’s how you can implement it:

1. Create a DP table where `dp[j]` represents the maximum value that can be obtained with a total volume of `j`.
2. Initialize the DP table with zeros.
3. Iterate over each item and update the DP table from right to left (to avoid using an item more than once).
4. For each item, if its volume is less than or equal to the current capacity `j`, update the DP table by considering whether to include the item or not.

Here's the complete implementation:

*/

#include <vector>
using namespace std;

class Solution {
public:
    int solve(int N, int V, vector<int>& v, vector<int>& w) {
        // Initialize the DP table with zeros
        vector<int> dp(V + 1, 0);
        
        // Iterate over each item
        for (int i = 0; i < N; ++i) {
            // Update the DP table from right to left
            for (int j = V; j >= v[i]; --j) {
                // Update dp[j] by considering whether to include item i
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        // The answer is the maximum value that can be obtained with volume V
        return dp[V];
    }
};

/*

### Explanation:
- **Initialization**: We initialize a DP array `dp` of size `V + 1` with all elements set to 0. This array will store the maximum value that can be achieved for each possible volume from 0 to `V`.
  
- **Iterating Over Items**: We iterate over each item from `0` to `N-1`. For each item, we update the DP table in reverse order (from `V` down to the volume of the current item). This ensures that each item is only used once.

- **Updating DP Table**: For each volume `j`, we check if including the current item would yield a higher value than the previously computed value for that volume. If so, we update `dp[j]`.

- **Result**: Finally, `dp[V]` contains the maximum value that can be obtained without exceeding the backpack's capacity `V`.

This approach ensures that we efficiently compute the maximum value while adhering to the constraints provided.

*/

#endif