#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a)
    {
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n - 1 - i; i++)
            ans += a[n - 1 - i] - a[i];
        return ans;
    }
};



#endif