#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a)
    {
        int ans = 0;
        for (int i = 1; i <= n - 1 - i; i++)
        {
            int x = a[i];
            int y = a[n - 1 - i];
            int z = a[i - 1];
            int w = a[n - i];
            ans += min((x == z) + (y == w), (x == w) + (y == z));
        }
        if (n % 2 == 0)
            ans += (a[n / 2 - 1] == a[n / 2]);
        return ans;
    }
};



#endif