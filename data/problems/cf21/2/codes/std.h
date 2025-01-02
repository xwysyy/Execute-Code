#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(int &n, vector<int> &a)
    {
        long long ans = -1E18, mn = 1E18, mx = -1E18;
        for (int i = 0; i < n; i += 1)
        {
            long long x = a[i];
            if (i)
                ans = max({ans, x * mx, x * mn});
            mn = min(mn, x);
            mx = max(mx, x);
        }
        return ans;
    }
};



#endif