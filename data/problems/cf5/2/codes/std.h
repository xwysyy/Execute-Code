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
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if(a[i]==a[i-1])cnt++;
            else cnt = 1;
            if(cnt==3)return a[i];
        }
        return -1;
    }
};



#endif