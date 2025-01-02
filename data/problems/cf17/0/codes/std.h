#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &a, int &b, int &c, int &d)
    {
        a -= b;
        c -= d;
        if (a < c || b > d)
            return -1;
        return (a - c) + (d - b);
    }
};



#endif