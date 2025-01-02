#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int n, int m, int k, int x, int y, vector<pair<int, int>> &a)
    {
        bool caught = false;
        for (int i = 0; i < k; i++)
        {
            int X = a[i].first, Y = a[i].second;
            if ((x + y + X + Y) % 2 == 0)
                caught = true;
        }
        return caught ? "YES" : "NO";
    }
};



#endif