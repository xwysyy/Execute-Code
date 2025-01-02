#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &a, int &b)
    {
        a = abs(a), b = abs(b);
        return min(a, b) * 2 + max(0, 2 * abs(b - a) - 1);
    }
};



#endif