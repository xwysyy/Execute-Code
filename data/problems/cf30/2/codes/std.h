#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> solve(int &n, string &s)
    {

        long long ans = 0;
        vector<long long> res;
        int l = n, r = n;
        for (int i = 1; i <= n; i++)
        {
            if (ans != -1)
            {
                if (l > n - i && s[n - i] == '0')
                    l -= 1;
                else
                {
                    while (l > 0 && s[l - 1] == '1')
                        l -= 1;
                    if (l == 0)
                        ans = -1;
                    else
                        ans += r - l;
                    l -= 1;
                }
                r -= 1;
            }
            res.push_back(ans);
        }
        return res;
    }
};



#endif