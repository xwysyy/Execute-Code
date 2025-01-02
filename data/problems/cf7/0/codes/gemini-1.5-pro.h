#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {
        int ans = 0;
        vector<int> dp(n, 0);
        if (s[0] == '1') {
            dp[0] = a[0];
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                dp[i] = max(dp[i - 1], (i > 1 ? dp[i - 2] : 0) + a[i]);
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};


#endif