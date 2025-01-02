#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &l, int &r, vector<int> &a)
    {
        vector<int> dp(n + 1);
        a.insert(a.begin(), 0);
        for (int i = 1; i <= n; i++)
            a[i] += a[i - 1];
        for (int i = 0, j = 0; i < n; i++)
        {
            for (; j <= n && a[j] - a[i] < l; j++);
            if (j <= n && a[j] - a[i] <= r)
                dp[j] = max(dp[j], dp[i] + 1);
            dp[i + 1] = max(dp[i + 1], dp[i]);
        }
        return dp[n];
    }
};



#endif