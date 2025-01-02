#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        if (s1[0] == '1' || s2[0] == '1' || s1[n-1] == '1' || s2[n-1] == '1') {
            return "NO";
        }
        
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '1' && s2[i] == '1') {
                return "NO";
            }
            if (i > 0 && s1[i] == '1' && s2[i-1] == '1' && s1[i-1] == '1') {
                return "NO";
            }
            if (i > 0 && s2[i] == '1' && s1[i-1] == '1' && s2[i-1] == '1') {
                return "NO";
            }
        }
        
        return "YES";
    }
};

#endif