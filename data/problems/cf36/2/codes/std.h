#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a)
    {

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int ans = 0;
        for (int i = 0, j = 0; i < a.size(); i++)
        {
            while (j < a.size() && a[j] < a[i] + n)
                j++;
            ans = max(ans, j - i);
        }
        return ans;
    }
};



#endif