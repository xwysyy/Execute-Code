#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        int dp[n + 1][4];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 4; j++) {
                dp[i][j] = n + 1;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
                if (j == 0 && s[i] == 'p') {
                    dp[i + 1][1] = min(dp[i + 1][1], dp[i][j]);
                } else if (j == 1 && s[i] == 'i') {
                    dp[i + 1][2] = min(dp[i + 1][2], dp[i][j]);
                } else if (j == 2 && s[i] == 'e') {
                    dp[i + 1][3] = min(dp[i + 1][3], dp[i][j]);
                } else if (j == 0 && s[i] == 'm') {
                    dp[i + 1][1] = min(dp[i + 1][1], dp[i][j]);
                } else if (j == 1 && s[i] == 'a') {
                    dp[i + 1][2] = min(dp[i + 1][2], dp[i][j]);
                } else if (j == 2 && s[i] == 'p') {
                    dp[i + 1][3] = min(dp[i + 1][3], dp[i][j]);
                } else {
                     if(j!=3) dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                }

            }
        }
        return dp[n][3];
    }
};


#endif