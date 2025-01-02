#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) {
        long long ans = (long long)n * m;
        if (ans % 2 == 0)
            return ans / 2;
        else
            return ans / 2 + 1;
    }
};


#endif