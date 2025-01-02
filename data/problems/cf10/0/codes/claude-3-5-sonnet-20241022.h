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
        
        // Find all positions where green appears
        vector<int> green_pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'g') {
                green_pos.push_back(i);
            }
        }
        
        // If no green lights exist, return -1 (though problem guarantees solution exists)
        if (green_pos.empty()) return -1;
        
        int ans = n;  // Maximum possible wait time
        
        // For each position where current color appears
        for (int pos : positions) {
            int max_wait = 0;
            // Find minimum time to reach next green from this position
            for (int g : green_pos) {
                if (g >= pos) {
                    max_wait = g - pos;
                    break;
                }
                // If no green after current position, we need to wait till next cycle
                max_wait = n - pos + g;
            }
            ans = min(ans, max_wait);
        }
        
        return ans;
    }
};


#endif