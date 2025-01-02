#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int res = 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(dp[i + 1], dp[i]);
            if (i == 0 || (i > 0 && dp[i] > dp[i - 1])) {
                dp[i + 1] = max(dp[i + 1], dp[i] + a[i] + 1);
            } else if (i > 0) {
                dp[i + 1] = max(dp[i + 1], dp[i - 1] + a[i] + 1);
            }
        }
        return dp[n];
    }
};


#endif