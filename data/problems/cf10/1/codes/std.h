#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, char &c, string &s)
    {
        int ans = 0, x = 0;
        for (int t = 0; t < 2; t++)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == 'g')
                    x = 0;
                else
                    x++;
                if (s[i] == c && t)
                    ans = max(ans, x);
            }
        }
        return ans;
    }
};



#endif