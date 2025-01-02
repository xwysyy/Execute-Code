#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {
        vector<bool> covered(n, false);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (i > 0 && !covered[i-1] && a[i-1] > a[i]) {
                    covered[i-1] = true;
                } else {
                    covered[i] = true;
                }
            }
        }
        int total = 0;
        for (int i = 0; i < n; ++i) {
            if (covered[i]) {
                total += a[i];
            }
        }
        return total;
    }
};


#endif