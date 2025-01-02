#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int &n, string &s1, string &s2)
    {
        bool flag = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (i % 2 == 0 && s2[i] == '<' && s1[i + 1] == '<')
                flag = 1;
            if (i % 2 == 1 && s2[i + 1] == '<' && s1[i] == '<')
                flag = 1;
        }
        return flag ? "NO" : "YES";
    }
};



#endif