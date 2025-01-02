#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a)
    {
        sort(a.begin(), a.end());
        int ans = 0, pre = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == pre)
            {
                cnt++;
                ans = max(ans, cnt);
            }
            else
            {
                cnt = 1;
                pre = a[i];
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};




#endif