#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &s)
    {
        int n = int(s.size());
        int ans = 0;
        for (int len = n / 2; len >= 1; len--)
        {
            int t = 0;
            for (int i = 0; i + len < n; i++)
            {
                if (s[i] == s[i + len] || s[i] == '?' || s[i + len] == '?')
                {
                    t += 1;
                    if (t == len)
                    {
                        ans = max(ans, len);
                        break;
                    }
                }
                else
                    t = 0;
            }
        }
        return ans * 2;
    }
};



#endif