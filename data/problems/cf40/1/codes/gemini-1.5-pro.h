#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s) {
        int n = s.length();
        int maxLen = 0;
        for (int len = 2; len <= n; len += 2) {
            for (int i = 0; i <= n - len; ++i) {
                bool isTandem = true;
                for (int j = 0; j < len / 2; ++j) {
                    if (s[i + j] != '?' && s[i + len / 2 + j] != '?' && s[i + j] != s[i + len / 2 + j]) {
                        isTandem = false;
                        break;
                    }
                }
                if (isTandem) {
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen;
    }
};


#endif