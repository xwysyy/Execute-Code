#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {   
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'E' && s[(i + 1) % n] == 'E') {
                continue;
            } else if (s[i] == 'N' && s[(i + 1) % n] == 'N') {
                continue;
            } else if (s[i] == 'E' && s[(i + 1) % n] == 'N') {
                continue;
            } else if (s[i] == 'N' && s[(i + 1) % n] == 'E') {
                return "NO";
            }
        }
        return "YES";
    }
};

#endif