#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int &n, vector<int> &a)
    {
        int l = a[0], r = a[0];
        bool ok = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == l - 1)
                l--;
            else if (a[i] == r + 1)
                r++;
            else
            {
                ok = false;
                break;
            }
        }
        return ok ? "YES" : "NO";
    }
};



#endif