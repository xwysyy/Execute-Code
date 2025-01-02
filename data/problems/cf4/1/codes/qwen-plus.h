#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {   
        // If all pairs are equal or there is at least one 'E' and no consecutive 'N's, return "YES"
        bool hasE = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'E') {
                hasE = true;
            }
            if (s[i] == 'N' && s[(i + 1) % n] == 'N') {
                return "NO";
            }
        }
        if (hasE || n % 2 == 0) {
            return "YES";
        }
        return "NO";
    }
};


#endif