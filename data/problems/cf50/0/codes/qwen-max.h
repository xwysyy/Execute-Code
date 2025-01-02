#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a) {
        vector<int> dp(n, 0);
        dp[0] = a[0];
        if (n > 1) {
            dp[1] = max(a[0], a[1]);
        }
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + a[i]);
        }
        return dp[n-1];
    }
};

#endif