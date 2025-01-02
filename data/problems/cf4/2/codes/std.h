#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int &n, string &s)
    {
        int cnt = 0;
        for (auto x : s)
            if (x == 'N')
                cnt++;
        if (cnt == 1)
            return "NO";
        else
            return "YES";
    }
};



#endif