#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 1) return a[0] + 1;

        vector<int> dp(n, 0);
        dp[0] = a[0] + 1;
        dp[1] = max(a[0] + 1, a[1] + 1);

        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i] + 1);
        }

        return dp[n - 1];
    }
};

#endif