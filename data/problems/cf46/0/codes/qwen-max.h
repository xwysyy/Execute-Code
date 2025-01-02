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
                bool leftRegion = (i > 0 && s1[i-1] == '.');
                bool rightRegion = (i < n-1 && s1[i+1] == '.');
                bool downRegion = (s2[i] == 'x' && (i > 0 && s2[i-1] == '.' || i < n-1 && s2[i+1] == '.'));
                if (leftRegion + rightRegion + downRegion == 2) {
                    count++;
                }
            } else if (s1[i] == 'x' && s2[i] == '.') {
                // Check if blocking s2[i] creates 3 regions
                bool leftRegion = (i > 0 && s2[i-1] == '.');
                bool rightRegion = (i < n-1 && s2[i+1] == '.');
                bool upRegion = (s1[i] == 'x' && (i > 0 && s1[i-1] == '.' || i < n-1 && s1[i+1] == '.'));
                if (leftRegion + rightRegion + upRegion == 2) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

#endif