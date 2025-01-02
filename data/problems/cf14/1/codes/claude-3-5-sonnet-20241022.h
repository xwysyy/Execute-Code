#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        // Create dp arrays to store maximum and minimum possible sums up to index i
        vector<long long> dp_max(n), dp_min(n);
        
        // Base case: first element can't be flipped alone
        dp_max[0] = dp_min[0] = a[0];
        
        // For each position, we either:
        // 1. Keep the current pair of numbers as is
        // 2. Flip the current pair of numbers
        for(int i = 1; i < n; i++) {
            if(i == 1) {
                // For position 1, we only have one choice to flip with position 0
                long long flip = -a[i-1] - a[i];
                long long noFlip = a[i];
                dp_max[i] = max(flip + dp_max[i-1], noFlip);
                dp_min[i] = min(flip + dp_min[i-1], noFlip);
            } else {
                // For other positions, we can either flip with previous or keep as is
                long long flip = -a[i-1] - a[i] + dp_max[i-2];
                long long noFlip = a[i] + dp_max[i-1];
                dp_max[i] = max(flip, noFlip);
                
                flip = -a[i-1] - a[i] + dp_min[i-2];
                noFlip = a[i] + dp_min[i-1];
                dp_min[i] = min(flip, noFlip);
            }
        }
        
        return dp_max[n-1];
    }
};


#endif