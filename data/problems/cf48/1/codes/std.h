#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solve(int &n, int &m, vector<int> &a, vector<array<int, 3>> &ops)
    {
        vector<int> res;
        int mx = *max_element(a.begin(), a.end());
        for (auto &[op, l, r] : ops)
        {
            if (l <= mx && mx <= r)
                mx += op == 1 ? 1 : -1;
            res.push_back(mx);
        }
        return res;
    }
};



#endif