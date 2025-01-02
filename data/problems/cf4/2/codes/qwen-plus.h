#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {   
        if (n == 2) return s == "N" ? "YES" : "YES";
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'E' || s[(i + 1) % n] == 'E') return "YES";
        }
        return "NO";
    }
};

#endif