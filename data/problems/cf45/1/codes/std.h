#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(int &n, long long &m, vector<int> &a)
    {
        sort(a.begin(), a.end());
        long long max_sum = 0, current_sum = 0;
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            current_sum += a[r];
            while (l <= r && (a[r] - a[l] > 1 || current_sum > m))
            {
                current_sum -= a[l];
                l++;
            }
            max_sum = max(max_sum, current_sum);
        }
        return max_sum;
    }
};



#endif