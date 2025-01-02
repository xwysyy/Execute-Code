#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Create a copy of the original array
        vector<int> rev = a;
        reverse(rev.begin(), rev.end());
        
        // For each position i, we can either keep original element
        // or use the element from reversed array
        int minDist = n;  // Initialize with max possible value
        
        // Try all possible combinations using bit manipulation
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> curr(n);
            for (int i = 0; i < n; i++) {
                // If i-th bit is set, use element from reversed array
                // Otherwise use element from original array
                curr[i] = (mask & (1 << i)) ? rev[i] : a[i];
            }
            
            // Count disturbance in current arrangement
            int dist = 0;
            for (int i = 0; i < n-1; i++) {
                if (curr[i] == curr[i+1]) {
                    dist++;
                }
            }
            
            minDist = min(minDist, dist);
        }
        
        return minDist;
    }
};


#endif