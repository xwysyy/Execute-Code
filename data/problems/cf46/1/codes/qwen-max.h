#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) { 
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '.' && s2[i] == 'x') {
                // Check if blocking s1[i] creates 3 regions
                bool left = (i > 0 && s1[i-1] == '.');
                bool right = (i < n-1 && s1[i+1] == '.');
                bool down = (i < n-1 && s2[i+1] == '.');
                if (left && right && down) count++;
            } else if (s1[i] == 'x' && s2[i] == '.') {
                // Check if blocking s2[i] creates 3 regions
                bool left = (i > 0 && s2[i-1] == '.');
                bool right = (i < n-1 && s2[i+1] == '.');
                bool up = (i > 0 && s1[i-1] == '.');
                if (left && right && up) count++;
            }
        }
        return count;
    }
};

#endif