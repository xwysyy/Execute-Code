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
            bool found = false;
            for (int i = 0; i + 2 * len <= n && !found; ++i) {
                bool valid = true;
                for (int j = 0; j < len && valid; ++j) {
                    if (s[i + j] != '?' && s[i + len + j] != '?' && s[i + j] != s[i + len + j]) {
                        valid = false;
                    }
                }
                if (valid) {
                    maxLength = 2 * len;
                    found = true;
                }
            }
            if (found) break;
        }

        // Handle the case where we can maximize tandem repeats by replacing '?'
        for (int i = 0; i < n - 1; ++i) {
            if ((s[i] == '?' || s[i + 1] == '?') && (i + 2 >= n || s[i] == s[i + 2] || s[i + 1] == s[i + 3] || s[i] == '?' || s[i + 1] == '?')) {
                maxLength = max(maxLength, 2);
            }
        }

        return maxLength;
    }
};


#endif