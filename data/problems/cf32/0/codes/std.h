#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<pair<int, int>> &edges)
    {
        vector<int> deg(n);
        for (auto [x, y] : edges)
            deg[x - 1]++, deg[y - 1]++;
        int ans = (std::count(deg.begin(), deg.end(), 1) + 1) / 2;
        return ans;
    }
};



#endif