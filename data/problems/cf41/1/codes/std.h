#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n)
    {
        int p = a[0];
        vector<int> ans(q);
        for (int i = 0; i < q; i++)
            ans[i] = min(p - 1, n[i]);
        return ans;
    }
};



#endif