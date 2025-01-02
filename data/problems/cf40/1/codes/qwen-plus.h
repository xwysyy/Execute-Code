#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s) {
        int n = s.size();
        int ans = 0;
        
        for (int len = n / 2; len > 0; --len) {
            bool found = false;
            for (int i = 0; i + 2 * len <= n && !found; ++i) {
                int mismatches = 0;
                for (int j = 0; j < len; ++j) {
                    if (s[i + j] != s[i + len + j] && (s[i + j] != '?' && s[i + len + j] != '?')) {
                        mismatches = -1;
                        break;
                    }
                    if (s[i + j] == '?' || s[i + len + j] == '?') {
                        mismatches++;
                    }
                }
                if (mismatches >= 0) {
                    found = true;
                    ans = max(ans, 2 * len);
                }
            }
            if (found) break;
        }
        return ans;
    }
};


#endif