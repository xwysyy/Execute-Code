#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a)
    {
        vector<int> dp(n);
        x--;
        dp[x] = 1;
        for (int i = 0; i < m; i++)
        {
            auto [r, c] = a[i];
            vector<int> g(n);
            for (int j = 0; j < n; j++)
            {
                if (dp[j])
                {
                    if (c != '1')
                        g[(j + r) % n] = 1;
                    if (c != '0')
                        g[(j - r + n) % n] = 1;
                }
            }
            dp = g;
        }
        return count(dp.begin(), dp.end(), 1);
    }
};





#endif