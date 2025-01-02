#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, string &s1, string &s2)
    {
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (s1[i] == '.' && s1[i - 1] == '.' && s1[i + 1] == '.' && s2[i] == '.' && s2[i - 1] == 'x' && s2[i + 1] == 'x')
                ans++;
            if (s2[i] == '.' && s2[i - 1] == '.' && s2[i + 1] == '.' && s1[i] == '.' && s1[i - 1] == 'x' && s1[i + 1] == 'x')
                ans++;
        }
        return ans;
    }
};



#endif