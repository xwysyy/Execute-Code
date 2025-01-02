#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, string &s) {
        // If m is 1, we just need to count zeros and use Timar on each
        if (m == 1) {
            int zeros = 0;
            for (char c : s) {
                if (c == '0') zeros++;
            }
            return (zeros + k - 1) / k;
        }
        
        int result = 0;
        int lastStrengthened = -k;  // Position where last Timar was used
        
        // Iterate through the string
        for (int i = 0; i <= n - m; i++) {
            // Check if current window of size m is all zeros
            bool allZeros = true;
            for (int j = i; j < i + m && allZeros; j++) {
                if (s[j] == '1') allZeros = false;
            }
            
            // If we found a weak interval
            if (allZeros) {
                // If previous strengthening doesn't cover this interval
                if (i >= lastStrengthened + k) {
                    // Apply Timar at the rightmost possible position
                    int strengthenPos = max(i, i + m - k);
                    lastStrengthened = strengthenPos;
                    result++;
                    
                    // Mark the strengthened positions
                    for (int j = strengthenPos; j < min(n, strengthenPos + k); j++) {
                        s[j] = '1';
                    }
                }
            }
        }
        
        return result;
    }
};


#endif