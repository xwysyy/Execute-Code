#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        vector<int> b = a;
        sort(b.begin(), b.end());
        int median_index = (n - 1) / 2;
        return b[median_index];
    }
};


#endif