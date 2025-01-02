#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Check if the start or end positions have traps
        if (s1[0] == '1' || s2[n-1] == '1') return "NO";
        
        // Check for impossible paths due to consecutive traps in both rows
        for (int i = 0; i < n; ++i) {
            if ((s1[i] == '1' && s2[i] == '1') ||
                (i > 0 && s1[i] == '1' && s2[i-1] == '1' && s1[i-1] == '0' && s2[i] == '0') ||
                (i < n-1 && s1[i] == '0' && s2[i+1] == '1' && s1[i+1] == '1' && s2[i] == '0')) {
                return "NO";
            }
        }
        return "YES";
    }
};


#endif