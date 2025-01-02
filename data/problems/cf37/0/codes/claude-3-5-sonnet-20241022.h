#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {   
        int minRemove = n;  // Maximum possible removals
        
        // Try all possible combinations of character removals using bitmask
        for (int mask = 0; mask < (1 << n); mask++) {
            string temp = "";
            int removedCount = 0;
            
            // Construct string based on current mask
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    temp += s[i];
                } else {
                    removedCount++;
                }
            }
            
            // Check if resulting string is beautiful
            bool isUgly = false;
            for (int i = 0; i + 2 < temp.length(); i++) {
                if ((temp[i] == 'p' && temp[i+1] == 'i' && temp[i+2] == 'e') ||
                    (temp[i] == 'm' && temp[i+1] == 'a' && temp[i+2] == 'p')) {
                    isUgly = true;
                    break;
                }
            }
            
            // Update minimum removals if string is beautiful
            if (!isUgly) {
                minRemove = min(minRemove, removedCount);
            }
        }
        
        return minRemove;
    }
};


#endif