#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, string &s) {   
        int min_time = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                for (int j = i; ; j = (j + 1) % n) {
                    if (s[j] == 'g') {
                        min_time = min(min_time, j - i + (j < i ? n : 0));
                        break;
                    }
                }
            }
        }
        return min_time;
    }
};


#endif