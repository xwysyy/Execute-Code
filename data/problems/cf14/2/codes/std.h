#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(int &n, vector<int> &a)
    {
        long long sum = 0;
        int neg = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                neg++;
                a[i] = -a[i];
            }
            sum += a[i];
        }
        if (neg % 2 == 1)
        {
            int mn = *min_element(a.begin(), a.end());
            sum -= 2 * mn;
        }
        return sum;
    }
};



#endif