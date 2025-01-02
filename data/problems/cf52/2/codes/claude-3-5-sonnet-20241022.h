#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<vector<int>> &a) {
        long long operations = 0;
        
        // Keep applying operations until no negative numbers remain
        bool hasNegative;
        do {
            hasNegative = false;
            // Find the diagonal that covers the most negative numbers
            int bestI = 0, bestJ = 0, bestLen = 0;
            int maxNegatives = 0;
            
            // Try all possible starting positions
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Try all possible lengths from this starting position
                    for (int len = 1; i + len - 1 < n && j + len - 1 < n; len++) {
                        int negCount = 0;
                        // Count negative numbers on this diagonal
                        for (int k = 0; k < len; k++) {
                            if (a[i + k][j + k] < 0) {
                                negCount++;
                                hasNegative = true;
                            }
                        }
                        if (negCount > maxNegatives) {
                            maxNegatives = negCount;
                            bestI = i;
                            bestJ = j;
                            bestLen = len;
                        }
                    }
                }
            }
            
            // If we found negative numbers, apply the operation
            if (hasNegative) {
                operations++;
                // Increment elements along the best diagonal
                for (int k = 0; k < bestLen; k++) {
                    a[bestI + k][bestJ + k]++;
                }
            }
            
        } while (hasNegative);
        
        return operations;
    }
};


#endif