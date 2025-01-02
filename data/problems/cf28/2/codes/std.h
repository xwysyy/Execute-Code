#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(string &a, string &b)
    {
        int n = a.size();
        for (int i = 0; i < n - 1; i++)
            if (a[i] == '0' && b[i] == '0' && a[i + 1] == '1' && b[i + 1] == '1')
                return "YES";
        return "NO";
    }
};



#endif