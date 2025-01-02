#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a)
    {
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n && a[i + 1] >= a[i])
                mx = max(mx, a[i]);
            if (i + 2 < n && a[i + 2] >= a[i])
                mx = max(mx, a[i]);
            if (i - 1 >= 0 && a[i - 1] >= a[i])
                mx = max(mx, a[i]);
            if (i - 2 >= 0 && a[i - 2] >= a[i])
                mx = max(mx, a[i]);
        }
        return mx;
    }
};



#endif