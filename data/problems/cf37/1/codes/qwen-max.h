#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {   
        int minRemovals = n;
        for (int i = 0; i < 2; ++i) {
            string forbidden = (i == 0) ? "pie" : "map";
            int dp[4] = {0, -1, -1, -1};
            for (int j = 0; j < n; ++j) {
                if (s[j] == forbidden[1]) {
                    dp[1] = max(dp[1], dp[0] + 1);
                } else if (s[j] == forbidden[2]) {
                    dp[2] = max(dp[2], dp[1] + 1);
                } else if (s[j] == forbidden[3]) {
                    dp[3] = max(dp[3], dp[2] + 1);
                }
                dp[0] = max(dp[0], (s[j] != forbidden[0]) ? dp[0] + 1 : 0);
            }
            minRemovals = min(minRemovals, n - max({dp[0], dp[1], dp[2], dp[3]}));
        }
        return minRemovals;
    }
};

#endif