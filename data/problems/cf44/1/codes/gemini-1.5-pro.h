#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &l, int &r, vector<int> &a) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            long long sum = 0;
            for (int j = i; j >= 1; j--) {
                sum += a[j - 1];
                if (sum >= l && sum <= r) {
                    dp[i] = max(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n];
    }
};


#endif