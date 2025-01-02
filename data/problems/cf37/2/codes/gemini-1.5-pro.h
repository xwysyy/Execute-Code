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
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
                if (j == 0) {
                    if (s[i] == 'p') {
                        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0]);
                    } else if (s[i] == 'm') {
                        dp[i + 1][2] = min(dp[i + 1][2], dp[i][0]);
                    } else {
                        dp[i + 1][0] = min(dp[i + 1][0], dp[i][0]);
                    }
                } else if (j == 1) {
                    if (s[i] == 'i') {
                        dp[i + 1][3] = min(dp[i + 1][3], dp[i][1]);
                    } else {
                        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
                    }
                } else if (j == 2) {
                    if (s[i] == 'a') {
                        dp[i + 1][1] = min(dp[i + 1][1], dp[i][2]);
                    } else {
                        dp[i + 1][0] = min(dp[i + 1][0], dp[i][2]);
                    }

                } else {
                    if (s[i] == 'e') {
                         dp[i + 1][0] = min(dp[i + 1][0], dp[i][3]);
                    } else {
                         dp[i + 1][0] = min(dp[i + 1][0], dp[i][3]);
                    }
                    if(s[i] == 'p'){
                         dp[i + 1][0] = min(dp[i + 1][0], dp[i][3]);
                    }

                }
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 4; i++) {
            ans = min(ans, dp[n][i]);
        }
        return ans;
    }
};


#endif