#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int &n, string &s)
    {
        int cur = 0;
        for (int i=n-1;i>=0;i--)
        {
            if (s[i] == 'A')
                cur++;
            else
                cur--;
            if (cur < 0)
                return "NO";
        }
        return "YES";
    }
};



#endif