#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b)
    {
        sort(b.begin(), b.end());
        sort(a.begin(), a.end());
        long long ans = 0;
        int l1 = 0, l2 = 0, r1 = n - 1, r2 = m - 1;
        for (int i = 0; i < n; i++)
        {
            if ((r2 >= 0) && (b[r2] - a[l1] > a[r1] - b[l2]))
                ans += b[r2] - a[l1], r2--, l1++;
            else
                ans += a[r1] - b[l2], r1--, l2++;
        }
        return ans;
    }
};



#endif