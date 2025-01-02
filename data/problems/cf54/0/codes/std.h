#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a)
    {
        set<int> s;
        s.insert(0);
        int sum = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            ans += s.count(sum) ? (s.clear(), s.insert(0), sum = 0, 1) : 0;
            s.insert(sum);
        }
        return ans;
    }
};



#endif