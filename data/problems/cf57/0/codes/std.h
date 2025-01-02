#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &k, vector<pair<int, int>> &bottle)
    {
        n = min(n, k);
        vector<int> s(k);
        for (int i = 0; i < k; i++)
        {
            int b = bottle[i].first;
            int c = bottle[i].second;
            b--;
            s[b] += c;
        }
        sort(s.begin(), s.end(), greater<int>());
        int ans = accumulate(s.begin(), s.begin() + n, 0);
        return ans;
    }
};



#endif