#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(int &n, vector<vector<int>> &a)
    {
        long long ans = 0;
        for (int i = -n + 1; i <= n - 1; i++)
        {
            int mi = 0;
            for (int j = max(0, i); j < n && j - i < n; j++)
                mi = min(mi, a[j - i][j]);
            ans += mi;
        }
        return -ans;
    }
};



#endif