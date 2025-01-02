#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s) {
        int n = s.size();
        int maxLength = 0;
        
        for (int len = n / 2; len > 0; --len) {
            bool valid = true;
            for (int i = 0; i + 2 * len <= n; ++i) {
                bool isValidTandem = true;
                for (int j = 0; j < len; ++j) {
                    if (s[i + j] != '?' && s[i + len + j] != '?' && s[i + j] != s[i + len + j]) {
                        isValidTandem = false;
                        break;
                    }
                }
                if (isValidTandem) {
                    maxLength = 2 * len;
                    goto found;
                }
            }
        }
        found:
        return maxLength;
    }
};


#endif