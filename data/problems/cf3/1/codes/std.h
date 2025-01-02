#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int &n, string &s1, string &s2)
    {
        for (int i = 0; i < n; i++)
            if (s1[i] == '1' && s2[i] == '1')
                return "NO";
        return "YES";
    }
};



#endif