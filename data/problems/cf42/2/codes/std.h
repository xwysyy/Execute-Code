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
            if (x == 'U')
                cnt++;
        return (cnt % 2) ? "YES" : "NO";
    }
};



#endif