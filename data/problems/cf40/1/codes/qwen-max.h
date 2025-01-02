#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &s) {
        int n = s.length();
        int maxLen = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int len = 1; i + 2 * len <= n; ++len) {
                bool isTandemRepeat = true;
                for (int j = 0; j < len; ++j) {
                    if (s[i + j] != '?' && s[i + j] != s[i + j + len]) {
                        isTandemRepeat = false;
                        break;
                    }
                }
                if (isTandemRepeat) {
                    maxLen = max(maxLen, 2 * len);
                }
            }
        }
        return maxLen;
    }
};

#endif