#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(string &s)
    {
        int n = s.size();
        if (count(s.begin(), s.end(), '0') == 0)
            return 1LL * n * n;
        s = s + s;
        long long ans = 0;
        for (int i = 0, j; i < n; i++)
        {
            if (s[i] == '1')
            {
                j = i;
                while (s[j] == '1')
                    j++;
                int d = j - i + 1;
                ans = max(ans, 1LL * (d / 2) * (d - d / 2));
                i = j;
            }
        }
        return ans;
    }
};



#endif