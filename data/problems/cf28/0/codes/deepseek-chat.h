#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        int n = a.length();
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                // Check if the current position is a boundary where the characters differ
                // and if the previous and next characters are the same in both strings
                if (i > 0 && i < n - 1 && a[i - 1] == b[i - 1] && a[i + 1] == b[i + 1]) {
                    // If the characters are the same before and after, we can transform
                    continue;
                } else {
                    return "NO";
                }
            }
        }
        return "YES";
    }
};


#endif