#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a) {   
        sort(a.begin(), a.end());
        int cost = 0;
        for (int i = 0; i < n - 1; i += 2) {
            cost += a[i + 1] - a[i];
        }
        return cost;
    }
};


#endif