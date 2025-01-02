#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a)
    {
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            cur += __builtin_ctz(x);
        }
        int cnt[20]{};
        for (int i = 1; i <= n; i++)
            cnt[__builtin_ctz(i)]++;

        int ans = 0;
        for (int i = 19; i >= 0; i--)
        {
            while (cur < n && cnt[i])
            {
                cur += i;
                cnt[i]--;
                ans++;
            }
        }
        if (cur < n)
            ans = -1;
        return ans;
    }
};



#endif