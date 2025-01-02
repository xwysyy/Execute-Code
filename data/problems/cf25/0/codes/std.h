#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int &n)
    {
        int ok = 0;
        for (int i = 2; i <= n && !ok; i++)
        {
            long long sum = 1 + i + 1LL * i * i, p = 1LL * i * i;
            if (sum > n)
                break;
            while (sum < n)
                sum += p *= i;
            if (sum == n)
                ok = 1;
        }
        return ok ? "YES" : "NO";
    }
};



#endif