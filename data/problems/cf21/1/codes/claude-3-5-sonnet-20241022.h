#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long maxBeauty = LLONG_MIN;
        
        // Try all possible adjacent pairs after removing elements
        for (int i = 0; i < n - 1; i++) {
            // Consider current pair
            maxBeauty = max(maxBeauty, (long long)a[i] * a[i + 1]);
            
            // Try pairs after skipping elements in between
            for (int j = i + 2; j < n; j++) {
                maxBeauty = max(maxBeauty, (long long)a[i] * a[j]);
            }
        }
        
        return maxBeauty;
    }
};


#endif