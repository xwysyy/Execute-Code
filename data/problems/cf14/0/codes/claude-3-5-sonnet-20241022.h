#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        // Initialize dp arrays for both states
        vector<long long> dp0(n), dp1(n);
        
        // Base cases
        dp0[0] = a[0];  // No flip for first element
        dp1[0] = -a[0]; // Flipped first element
        
        if (n > 1) {
            dp0[1] = max(a[0] + a[1], -a[0] - a[1]);
            dp1[1] = max(-a[0] + a[1], a[0] - a[1]);
        }
        
        // Fill dp arrays
        for (int i = 2; i < n; i++) {
            // For current element not flipped
            dp0[i] = max(dp0[i-1] + a[i],    // Don't flip current pair
                        dp1[i-1] - a[i]);     // Flip current pair
            
            // For current element flipped
            dp1[i] = max(dp0[i-1] - a[i],    // Flip current pair
                        dp1[i-1] + a[i]);     // Don't flip current pair
        }
        
        return max(dp0[n-1], dp1[n-1]);
    }
};


#endif