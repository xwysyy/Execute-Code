#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, string &s) {
        int minTime = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                for (int j = i; ; ++j) {
                    if (s[j % n] == 'g') {
                        minTime = min(minTime, j - i);
                        break;
                    }
                }
            }
        }
        return minTime;
    }
};

#endif