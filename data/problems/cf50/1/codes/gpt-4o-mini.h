#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 0) return 0;

        int maxScore = 0;

        // We can use dynamic programming to maintain the maximum score.
        vector<int> dp(n + 1, 0); // dp[i]: max score if considering up to index i

        dp[0] = 0; // No elements means no score
        dp[1] = a[0] + 1; // Take the first element

        for (int i = 2; i <= n; ++i) {
            // Option 1: Do not take a[i-1], so score remains the same as dp[i-1]
            dp[i] = dp[i-1];

            // Option 2: Take a[i-1], which is a[i-1] + 1 (number of red elements)
            dp[i] = max(dp[i], a[i-1] + 1 + (i > 2 ? dp[i-2] : 0)); // Add dp[i-2] if taking a[i-1]

            // Update max score found so far
            maxScore = max(maxScore, dp[i]);
        }

        return maxScore;
    }
};


#endif