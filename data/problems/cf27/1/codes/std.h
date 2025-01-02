#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int &n, vector<int> &a)
    {
        auto b = a;
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++)
        {
            if ((a[i] - b[i]) % 2)
                return "NO";
        }
        return "YES";
    }
};



#endif