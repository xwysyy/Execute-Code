#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &m, int &k, string &s)
    {
        s = "l" + s;
        int cnt = 0, ans = 0;
        int r = 0;
        for (int l = 1; l <= n; l++)
        {
            if (s[l] == '1')
                cnt = 0;
            else
            {
                if (s[l] == '0' && l > r)
                    cnt++;
                if (cnt == m)
                {
                    ans++;
                    cnt = 0;
                    r = l + k - 1;
                }
            }
        }
        return ans;
    }
};



#endif