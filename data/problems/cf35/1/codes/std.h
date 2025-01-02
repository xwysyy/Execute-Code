#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n)
    {
        string s = to_string(n);
        s = 'k' + s;
        n = s.size() - 1;
        int tem = pow(10, n - 1);
        int sum = 0;
        int ans = 0;
        int num = 0;
        for (int i = 1; i <= n; i++)
            num = num * 10 + (s[i] - '0');
        for (int i = 1; i <= n; i++)
        {
            int d = s[i] - '0';
            ans += sum * 45 * tem;
            sum = sum * 10 + d;
            ans += max(0, (d - 1 + 1) * (d - 1) / 2) * tem;
            num %= tem;
            ans += d * (num + 1);
            tem /= 10;
        }
        return ans;
    }
};



#endif