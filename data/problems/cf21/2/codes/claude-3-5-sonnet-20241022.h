#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long maxBeauty = LLONG_MIN;
        
        // Check all possible adjacent pairs after removing elements
        for (int i = 0; i < n - 1; i++) {
            // Calculate product of current adjacent elements
            long long product = (long long)a[i] * a[i + 1];
            maxBeauty = max(maxBeauty, product);
            
            // Check pairs that become adjacent after removing elements between them
            for (int j = i + 2; j < n; j++) {
                product = (long long)a[i] * a[j];
                maxBeauty = max(maxBeauty, product);
            }
        }
        
        return maxBeauty;
    }
};


#endif