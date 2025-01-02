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
        
        // Try all possible combinations of original and reversed elements
        int minDist = n;  // Maximum possible disturbance
        
        // For each position, we can either keep original or use reversed
        for (int mask = 0; mask < (1 << n); mask++) {
            int dist = 0;
            
            // Check if current combination is valid
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    // If position i is marked 1, it means we need to swap
                    // Check if this swap is valid (i and n-i-1 positions)
                    if (i >= n-i-1) {
                        valid = false;
                        break;
                    }
                }
            }
            
            if (!valid) continue;
            
            // Calculate disturbance for current combination
            for (int i = 0; i < n-1; i++) {
                int curr = ((mask >> i) & 1) ? rev[i] : a[i];
                int next = ((mask >> (i+1)) & 1) ? rev[i+1] : a[i+1];
                if (curr == next) dist++;
            }
            
            minDist = min(minDist, dist);
        }
        
        return minDist;
    }
};


#endif