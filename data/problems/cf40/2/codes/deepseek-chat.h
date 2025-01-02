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
                bool isTandem = true;
                for (int k = 0; k < len / 2; ++k) {
                    char a = s[i + k];
                    char b = s[i + len / 2 + k];
                    if (a != '?' && b != '?' && a != b) {
                        isTandem = false;
                        break;
                    }
                }
                if (isTandem && len > maxLen) {
                    maxLen = len;
                }
            }
        }
        
        return maxLen;
    }
};


#endif