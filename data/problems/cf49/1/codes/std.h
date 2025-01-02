#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, string &s)
    {
        int minans = 1000000000;
        for (int j = 0; j < 26; j++)
        {
            for (int t = 0; t < 26; t++)
            {
                int cans = 0;
                for (int i = 0; i < n / 2 * 2; i++)
                {
                    if (i % 2 == 0 && s[i] - 'a' != j)
                        cans++;
                    if (i % 2 == 1 && s[i] - 'a' != t)
                        cans++;
                }
                minans = min(minans, cans);
                if (n % 2 == 0)
                    continue;
                for (int i = n - 2; i > -1; i--)
                {
                    if (i % 2 == 0 && s[i] - 'a' != j)
                        cans--;
                    if (i % 2 == 1 && s[i] - 'a' != t)
                        cans--;
                    if (i % 2 == 0 && s[i + 1] - 'a' != j)
                        cans++;
                    if (i % 2 == 1 && s[i + 1] - 'a' != t)
                        cans++;
                    minans = min(minans, cans);
                }
            }
        }
        if (n % 2 == 0)
            return minans;
        else
            return minans + 1;
    }
};



#endif