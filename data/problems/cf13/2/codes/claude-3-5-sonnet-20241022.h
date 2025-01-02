#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        // Count current inversions
        long long curr_inv = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] > a[j]) curr_inv++;
            }
        }
        
        // Try flipping each element and calculate new inversions
        long long max_inv = curr_inv;
        
        for(int pos = 0; pos < n; pos++) {
            // Calculate change in inversions if we flip position pos
            long long change = 0;
            
            // Count how many 1s before pos and 0s after pos
            int ones_before = 0, zeros_after = 0;
            
            for(int i = 0; i < pos; i++) {
                if(a[i] == 1) ones_before++;
            }
            for(int i = pos + 1; i < n; i++) {
                if(a[i] == 0) zeros_after++;
            }
            
            if(a[pos] == 0) {
                // If flipping 0 to 1
                change = ones_before + zeros_after;
            } else {
                // If flipping 1 to 0
                change = (pos - ones_before) + (n - pos - 1 - zeros_after);
            }
            
            // If flipping creates more inversions, update max_inv
            if(a[pos] == 0) {
                max_inv = max(max_inv, curr_inv + change);
            } else {
                max_inv = max(max_inv, curr_inv - change);
            }
        }
        
        return max_inv;
    }
};


#endif