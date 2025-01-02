#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Check if the start or end cells are traps
        if (s1[0] == '1' || s2[n-1] == '1') return "NO";
        
        // Check for impossible paths due to consecutive traps in both rows
        for (int i = 0; i < n - 1; ++i) {
            if ((s1[i] == '1' && s1[i + 1] == '1') && (s2[i] == '1' && s2[i + 1] == '1')) {
                return "NO";
            }
        }
        
        // Check if it's possible to switch rows without hitting a trap
        bool onRow1 = true;
        for (int i = 0; i < n; ++i) {
            if (onRow1 && s1[i] == '1') {
                if (s2[i] == '1') return "NO"; // Can't switch rows
                onRow1 = false;
            } else if (!onRow1 && s2[i] == '1') {
                if (s1[i] == '1') return "NO"; // Can't switch rows
                onRow1 = true;
            }
        }
        
        return "YES";
    }
};


#endif