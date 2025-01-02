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
            int maxBenefit = 0;
            int bestI = 0, bestJ = 0, bestSize = 0;
            
            // Try all possible starting positions
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    // Try all possible sizes for the square
                    for(int size = 1; i + size - 1 < n && j + size - 1 < n; size++) {
                        int benefit = 0;
                        // Count negative numbers on this diagonal
                        for(int k = 0; k < size; k++) {
                            if(a[i + k][j + k] < 0) benefit++;
                        }
                        if(benefit > maxBenefit) {
                            maxBenefit = benefit;
                            bestI = i;
                            bestJ = j;
                            bestSize = size;
                        }
                    }
                }
            }
            
            // If we found negative numbers, apply the operation
            if(maxBenefit > 0) {
                operations++;
                for(int k = 0; k < bestSize; k++) {
                    a[bestI + k][bestJ + k]++;
                }
                hasNegative = true;
            }
            
            // Check if there are still negative numbers
            if(!hasNegative) {
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        if(a[i][j] < 0) {
                            hasNegative = true;
                            break;
                        }
                    }
                    if(hasNegative) break;
                }
            }
            
        } while(hasNegative);
        
        return operations;
    }
};


#endif