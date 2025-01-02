#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            a[i] = sum;
            sum += x;
        }
        a.push_back(sum);
        int ans = 0;
        for (int i = 0, j = 0; i < n; i++)
        {
            if (i && h[i - 1] % h[i] != 0)
                j = i;
            while (a[i + 1] - a[j] > k)
                j++;
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};



#endif