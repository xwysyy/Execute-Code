#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int dp[n + 1][2];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + a[i - 1] + 1;
        }
        return max(dp[n][0], dp[n][1]);
    }
};


#endif