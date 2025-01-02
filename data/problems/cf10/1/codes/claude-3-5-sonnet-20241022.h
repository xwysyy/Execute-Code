#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, string &s) {
        // Find all positions where current color appears
        vector<int> positions;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                positions.push_back(i);
            }
        }
        
        // Find minimum guaranteed time to reach green
        int result = n;
        for (int pos : positions) {
            // For each starting position, find next green
            int maxSteps = 0;
            for (int j = 0; j < n; j++) {
                if (s[(pos + j) % n] == 'g') {
                    maxSteps = j;
                    break;
                }
            }
            result = min(result, maxSteps);
        }
        
        return result;
    }
};


#endif