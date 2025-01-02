#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {
        // Sort array b to make it easier to find min/max values
        sort(b.begin(), b.end());
        
        long long totalDiff = 0;
        
        // For each position i, we want to maximize |a[i] - c[i]|
        // We can do this by choosing either the smallest or largest 
        // available value from b that gives maximum difference
        vector<bool> used(m, false);  // Track which elements from b we've used
        
        // Process each position
        for (int i = 0; i < n; i++) {
            long long maxDiff = 0;
            int bestIdx = 0;
            
            // Try both ends of array b
            // Check difference with smallest unused value
            for (int j = 0; j < m; j++) {
                if (!used[j]) {
                    long long diff = abs(1LL * a[i] - b[j]);
                    if (diff > maxDiff) {
                        maxDiff = diff;
                        bestIdx = j;
                    }
                    break;
                }
            }
            
            // Check difference with largest unused value
            for (int j = m - 1; j >= 0; j--) {
                if (!used[j]) {
                    long long diff = abs(1LL * a[i] - b[j]);
                    if (diff > maxDiff) {
                        maxDiff = diff;
                        bestIdx = j;
                    }
                    break;
                }
            }
            
            used[bestIdx] = true;  // Mark this value as used
            totalDiff += maxDiff;
        }
        
        return totalDiff;
    }
};


#endif