#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int &n, vector<int> &a, string &s)
    {
        vector<int> mp(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            if (mp[a[i]] == -1)
                mp[a[i]] = s[i];
            else if (mp[a[i]] != s[i])
                return "NO";
        }
        return "YES";
    }
};



#endif