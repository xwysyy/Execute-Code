#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int &n, int &a, int &b) {
        int x = abs(a);
        int y = abs(b);
        int ans = max(x, y);
        if (x == y) return ans;
        return ans + (max(x, y) - min(x, y));
    }
};


#endif