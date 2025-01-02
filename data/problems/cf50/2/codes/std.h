#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a)
    {
        int mx1 = 0, mx2 = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2)
            {
                mx1 = max(mx1, a[i]);
                cnt1++;
            }
            else
            {
                mx2 = max(mx2, a[i]);
                cnt2++;
            }
        }
        return max(mx1 + cnt1, mx2 + cnt2);
    }
};



#endif