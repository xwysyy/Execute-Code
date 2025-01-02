#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '-' || s[(i - 1 + n) % n] != '>' || s[(i + 1) % n] != '<') {
                count++;
            }
        }
        return count;
    }
};

#endif