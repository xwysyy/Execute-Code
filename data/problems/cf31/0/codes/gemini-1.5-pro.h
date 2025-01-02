#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) {
        long long ans = (long long)n * m;
        if (n % 2 == 0)
            ans = (long long)n / 2 * m;
        else if (m % 2 == 0)
            ans = (long long)m / 2 * n;
        else
            ans = (long long)(n * m + 1) / 2;
        return ans;
    }
};


#endif