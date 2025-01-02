#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        int dp[n + 1][4];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + 1;
            char c = s[i - 1];
            if (c == 'p') {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            } else if (c == 'i') {
                dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
            } else if (c == 'e') {
                dp[i][3] = min(dp[i - 1][2], dp[i - 1][3]);
            } else if (c == 'm') {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            } else if (c == 'a') {
                dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
            } else if (c == 'p' && i > 1 && s[i - 2] == 'm') {
                dp[i][3] = min(dp[i-1][2], dp[i-1][3]);
            }
             else {
                dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
                dp[i][2] = min(dp[i][2], dp[i - 1][2] + 1);
                dp[i][3] = min(dp[i][3], dp[i - 1][3] + 1);
            }
        }

        return min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]});
    }
};


#endif