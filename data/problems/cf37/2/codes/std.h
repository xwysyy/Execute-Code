#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, string &s)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i + 3 <= n && s.substr(i, 3) == "pie")
                ans++;
            if (i + 3 <= n && s.substr(i, 3) == "map")
                ans++;
            if (i + 5 <= n && s.substr(i, 5) == "mapie")
                ans--;
        }
        return ans;
    }
};



#endif