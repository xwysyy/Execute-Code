#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {
        int maxLen = 0;
        
        // Try each possible starting position
        for (int start = 0; start < n; start++) {
            int fruitSum = 0;
            int len = 0;
            
            // Extend the subarray as far as possible
            for (int end = start; end < n; end++) {
                // Check if adding this element would exceed k fruits
                if (fruitSum + a[end] > k) break;
                
                // For elements after the first one, check divisibility
                if (end > start && h[end-1] % h[end] != 0) break;
                
                fruitSum += a[end];
                len++;
                maxLen = max(maxLen, len);
            }
        }
        
        return maxLen;
    }
};


#endif