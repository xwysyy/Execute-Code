#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a)
    {
        int ans = 0;
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                t++;
            else
                t = 0;
            ans = max(ans, t);
        }
        return ans;
    }
};



#endif