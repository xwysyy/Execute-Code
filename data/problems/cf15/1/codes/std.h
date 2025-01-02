#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solve(int &n, vector<int> &a)
    {
        vector<int> ans;
        for (int i = 0, k = 0; i < n; i++)
        {
            while (k <= i && a[i - k] >= k + 1)
                k += 1;
            ans.push_back(k);
        }
        return ans;
    }
};



#endif