#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {   
        // If all pairs are equal or there is at least one 'E' and the rest can be consistent
        if (s.find("N") == string::npos || s.find("E") != string::npos && s.rfind("E") >= 0) {
            return "YES";
        }
        // Check for inconsistency in the information provided
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'N' && s[(i + 1) % n] == 'E') {
                return "NO";
            }
        }
        return "YES";
    }
};


#endif