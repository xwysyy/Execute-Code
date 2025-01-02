#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b)
    {

        int x = -2;
        for (int i = 0; i < n; i++)
        {
            if (a[i] + i <= t)
            {
                if (x == -2 || b[x] < b[i])
                    x = i;
            }
        }
        return x + 1;
    }
};



#endif