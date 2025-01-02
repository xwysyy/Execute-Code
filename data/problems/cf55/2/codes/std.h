#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &p)
    {
        int ans = 0;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            int j = i;
            int len = 0;
            while (!vis[j])
            {
                vis[j] = true;
                j = p[j];
                len++;
            }
            ans += (len - 1) / 2;
        }
        return ans;
    }
};



#endif