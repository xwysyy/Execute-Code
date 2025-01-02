#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, string &s)
    {
        int ans = 0;
        bool flaga = 1, flagb = 1;
        for (int i = 0; i < n; i++)
            if (s[i] != '-')
            {
                if (s[i] == '>')
                    flaga = 0;
                if (s[i] == '<')
                    flagb = 0;
            }
        if (flaga || flagb)
            return n;
        else
        {
            for (int i = 0; i < n; i++)
                if (s[i] == '-' || s[(i + 1) % n] == '-')
                    ans++;
            return ans;
        }
    }
};



#endif