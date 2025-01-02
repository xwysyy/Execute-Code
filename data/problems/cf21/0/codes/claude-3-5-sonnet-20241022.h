#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long maxBeauty = LLONG_MIN;
        
        // Check all possible pairs after removing elements in between
        for (int i = 0; i < n - 1; i++) {
            // Check adjacent elements
            maxBeauty = max(maxBeauty, (long long)a[i] * a[i + 1]);
            
            // Check elements after removing elements in between
            for (int j = i + 2; j < n; j++) {
                maxBeauty = max(maxBeauty, (long long)a[i] * a[j]);
            }
        }
        
        return maxBeauty;
    }
};


#endif