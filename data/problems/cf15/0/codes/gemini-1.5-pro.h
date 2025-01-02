#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solve(int &n, vector<int> &a) {
        vector<int> ans(n);
        vector<double> dp(n + 1, 0.0);
        vector<int> cnt(n + 1, 0);
        dp[0] = 1.0;
        cnt[0] = 1;
        double fact = 1.0;
        for (int i = 0; i < n; ++i) {
            fact = fact * (i + 1);
            for (int j = i + 1; j > 0; --j) {
                double cur = dp[j - 1] * a[i] / fact;
                if (cur > dp[j]) {
                    dp[j] = cur;
                    cnt[j] = cnt[j - 1];
                } else if (abs(cur - dp[j]) < 1e-9) {
                    cnt[j] += cnt[j - 1];
                }
            }
            int mx_cnt = 0;
            for (int j = 0; j <= i + 1; ++j) {
                if (abs(dp[j] - dp[mx_cnt]) < 1e-9)
                    mx_cnt = max(mx_cnt, cnt[j]);
                else if (dp[j] > dp[mx_cnt])
                    mx_cnt = cnt[j];
            }

            for (int j = 0; j <= i + 1; j++){
                if (abs(dp[j] - dp[mx_cnt]) < 1e-9){
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};


#endif