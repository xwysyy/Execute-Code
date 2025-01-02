#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {
        int ans = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                dp[i] = a[i];
                if (i > 0) {
                    dp[i] = max(dp[i], dp[i - 1]);
                }
            } else {
                if (i > 0) {
                    dp[i] = dp[i - 1];
                }
            }
        }
        vector<int> dp2(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                dp2[i] = a[i];
                if (i < n - 1) {
                    dp2[i] = max(dp2[i], dp2[i + 1]);
                }
            } else {
                if (i < n - 1) {
                    dp2[i] = dp2[i + 1];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int cur = 0;
            if (s[i] == '1') {
                cur += a[i];
                if (i > 0) {
                    cur += dp[i - 1];
                }
                if (i < n - 1) {
                    cur += dp2[i + 1];
                }

                ans = max(ans, cur);
            }
        }
        return ans;
    }
};


#endif