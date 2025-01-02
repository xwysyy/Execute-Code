#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &k, int &x, vector<int> &a)
    {
        sort(a.begin(), a.end());
        int ans = -1e9;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            a[i] = sum;
            sum += x;
        }
        a.push_back(sum);
        for (int i = 0; i <= k; i++)
        {
            int res = -a[n - i] + 2 * a[max(0, n - i - x)];
            ans = max(ans, res);
        }
        return ans;
    }
};



#endif