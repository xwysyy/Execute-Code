#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a)
    {
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            int res = 0;
            for (int j = 0; j < n; j++)
            {
                if (j < i || a[j] > a[i])
                    res++;
            }
            ans = min(ans, res);
        }
        return ans;
    }
};



#endif