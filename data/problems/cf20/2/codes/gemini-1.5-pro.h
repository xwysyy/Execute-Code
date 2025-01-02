#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {
        int ans = -1;
        int max_b = -1;
        for (int i = 0; i < n; ++i) {
            if (i + 1 + a[i] <= t) {
                if (b[i] > max_b) {
                    max_b = b[i];
                    ans = i + 1;
                }
            }
        }
        return ans;
    }
};


#endif