#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        vector<int> dp(n + 1, 0); // dp[i] represents maximum score using first i elements
        dp[0] = 0; // No elements means score is 0

        for (int i = 1; i <= n; i++) {
            // Option 1: Do not pick the i-th element
            dp[i] = dp[i - 1];

            // Option 2: Pick the i-th element
            // If we pick i-th, we cannot pick (i-1)th, so we check (i-2)th
            if (i > 1) {
                dp[i] = max(dp[i], a[i - 1] + 1 + dp[i - 2]);
            } else {
                dp[i] = max(dp[i], a[i - 1] + 1); // if this is the first element
            }
        }

        return dp[n];
    }
};


#endif