#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(int &n, int &c, int &d, vector<int> &a)
    {
        sort(a.begin(), a.end());
        long long ans = 1LL * c * n + d;
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || a[i] != a[i - 1])
                t++;
            ans = min(ans, 1LL * c * n + 1LL * d * a[i] - 1LL * (c + d) * t);
        }
        return ans;
    }
};



#endif