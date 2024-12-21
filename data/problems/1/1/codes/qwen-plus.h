#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

/*

*/

class Solution {
public:
    int solve(int N, int V, vector<int>& v, vector<int>& w) {
        // Create a DP array where dp[j] represents the max value with volume j
        vector<int> dp(V + 1, 0);
        
        // Iterate over each item
        for (int i = 0; i < N; ++i) {
            // Iterate backward over the possible volumes
            for (int j = V; j >= v[i]; --j) {
                // Update dp[j] by considering the current item
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        // Return the maximum value that can be achieved with volume V
        return dp[V];
    }
};

/*

### Explanation:
- **Outer Loop (`for (int i = 0; i < N; ++i)`)**: Iterates through each item.
- **Inner Loop (`for (int j = V; j >= v[i]; --j)`)**: Iterates backward through the possible volumes to ensure each item is only used once per volume.
- **Update Rule (`dp[j] = max(dp[j], dp[j - v[i]] + w[i])`)**: Checks if including the current item (`v[i]` and `w[i]`) would yield a better value than the current best value for volume `j`.

### Example Walkthrough:
For `N = 3`, `V = 4`, `v = [4, 3, 1]`, and `w = [1, 2, 1]`:
- Initially, `dp` is `[0, 0, 0, 0, 0]`.
- After processing the first item (`v[0] = 4`, `w[0] = 1`), `dp` becomes `[0, 0, 0, 0, 1]`.
- After processing the second item (`v[1] = 3`, `w[1] = 2`), `dp` becomes `[0, 0, 0, 2, 2]`.
- After processing the third item (`v[2] = 1`, `w[2] = 1`), `dp` becomes `[0, 1, 1, 2, 2]`.
- Finally, `dp[4]` is `2`, which is the maximum value that can be achieved with a capacity of `4`.

Thus, the output is `2`.

*/

#endif