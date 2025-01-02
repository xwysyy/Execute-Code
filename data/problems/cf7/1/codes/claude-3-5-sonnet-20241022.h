#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {
        // Create a boolean array to track which boxes are covered
        vector<bool> covered(n);
        
        // Initially, copy the lid positions from string s
        for (int i = 0; i < n; i++) {
            covered[i] = (s[i] == '1');
        }
        
        // For each position from left to right (except first position)
        for (int i = 1; i < n; i++) {
            // If current position has a lid
            if (s[i] == '1') {
                // Compare magazines in current position and previous position
                if (!covered[i-1] && a[i-1] > a[i]) {
                    // Move lid to previous position if it saves more magazines
                    covered[i-1] = true;
                    covered[i] = false;
                } else {
                    // Keep lid in current position
                    covered[i] = true;
                }
            }
        }
        
        // Calculate total magazines saved
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (covered[i]) {
                result += a[i];
            }
        }
        
        return result;
    }
};


#endif