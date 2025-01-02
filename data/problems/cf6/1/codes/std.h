#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int &n, vector<int> &a)
    {
        for (int i = 2; i < n; i++)
            if (a[i] % 2 != a[i - 2] % 2)
                return "NO";
        return "YES";
    }
};



#endif