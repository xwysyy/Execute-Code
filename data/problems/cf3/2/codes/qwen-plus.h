#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Check if the start or end cells have traps
        if (s1[0] == '1' || s2[n-1] == '1') return "NO";
        
        // Check for impossible paths due to consecutive traps
        for (int i = 0; i < n - 1; ++i) {
            if ((s1[i] == '1' && s1[i + 1] == '1') || (s2[i] == '1' && s2[i + 1] == '1')) {
                if (s1[i] == '1' && s2[i] == '1') return "NO";
                if (s1[i + 1] == '1' && s2[i + 1] == '1') return "NO";
            }
        }
        
        // Check if there is a way to switch rows without hitting traps
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '1' && s2[i] == '1') return "NO";
        }
        
        return "YES";
    }
};


#endif