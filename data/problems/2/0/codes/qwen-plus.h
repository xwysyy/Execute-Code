#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution {
public:
    int solve(int N, int V, std::vector<int>& v, std::vector<int>& w) {
        // Initialize the DP table with zeros
        std::vector<int> dp(V + 1, 0);
        
        // Iterate over each item
        for (int i = 0; i < N; ++i) {
            // Iterate over the volumes in reverse order to ensure each item is used at most once
            for (int j = V; j >= v[i]; --j) {
                // Update the DP table by considering the current item
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        // The answer is the maximum value that can be obtained with a total volume up to V
        return dp[V];
    }
};

/*

### Explanation:

1. **Initialization**:
   - We initialize a DP table `dp` of size `V + 1` with all elements set to 0. This table will store the maximum value that can be achieved for each possible volume from 0 to `V`.

2. **Iterating Over Items**:
   - For each item `i` (from 0 to `N-1`), we iterate over the possible volumes `j` in reverse order from `V` down to `v[i]`. This reverse iteration ensures that each item is only considered once for each volume.

3. **Updating the DP Table**:
   - For each volume `j`, we update `dp[j]` to be the maximum of its current value or the value obtained by including the current item (`dp[j - v[i]] + w[i]`).

4. **Result**:
   - After processing all items, `dp[V]` will contain the maximum value that can be achieved without exceeding the backpack's capacity `V`.

This approach ensures that we find the optimal solution while adhering to the constraints provided.

*/

#endif