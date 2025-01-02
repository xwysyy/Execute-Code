#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(int &n, vector<int> &a)
    {
        long long ans = 0;
        int c0 = 0, c1 = 0;
        int x0 = -1, x1 = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                c0++;
                ans += c1;
                if (x0 == -1)
                    x0 = i;
            }
            else
            {
                c1++;
                x1 = i;
            }
        }
        long long res = ans;
        if (x0 != -1)
            ans = max(ans, res + c0 - 1 - x0);
        if (x1 != -1)
            ans = max(ans, res + c1 - 1 - (n - 1 - x1));
        return ans;
    }
};



#endif