#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {
        int maxEntertainment = -1;
        int bestIndex = -1;
        
        // Check each video
        for (int i = 0; i < n; i++) {
            // Calculate total time needed:
            // i seconds to skip to video i (from start) + duration of video
            long long totalTime = (long long)i + a[i];
            
            // If we can watch this video within time t
            if (totalTime <= t) {
                // Update best video if current video has higher entertainment value
                if (b[i] > maxEntertainment) {
                    maxEntertainment = b[i];
                    bestIndex = i + 1;  // 1-based indexing
                }
            }
        }
        
        return bestIndex;
    }
};


#endif