#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, string &s, vector<int> &a)
    {
        for (int i = 0, j = -1; i < n; i++)
        {
            if (s[i] == '0')
                j = i;
            else if (j >= 0 && a[i] < a[j])
            {
                swap(s[i], s[j]);
                j = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                ans += a[i];
        return ans;
    }
};



#endif