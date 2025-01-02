#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s) {
        int n = s.length();
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; j += 2) {
                int len = j - i + 1;
                int half = len / 2;
                bool valid = true;
                for (int k = 0; k < half; ++k) {
                    char a = s[i + k];
                    char b = s[i + half + k];
                    if (a != '?' && b != '?' && a != b) {
                        valid = false;
                        break;
                    }
                }
                if (valid && len > maxLen) {
                    maxLen = len;
                }
            }
        }
        return maxLen;
    }
};


#endif