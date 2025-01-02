#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, string &s) {
        // If k >= m, we can always cover any weak interval with a single Timar
        if (k >= m) {
            // Count groups of consecutive zeros of length m
            int count = 0;
            for (int i = 0; i < n; i++) {
                int zeros = 0;
                while (i < n && s[i] == '0') {
                    zeros++;
                    if (zeros == m) {
                        count++;
                        break;
                    }
                    i++;
                }
            }
            return count;
        }
        
        // For k < m, we need to use a sliding window approach
        int result = 0;
        vector<bool> strengthened(n, false);  // Track strengthened positions
        
        for (int i = 0; i <= n - m; i++) {
            // Check if current window of size m has any strong spot
            bool needStrengthening = true;
            for (int j = i; j < i + m; j++) {
                if (s[j] == '1' || strengthened[j]) {
                    needStrengthening = false;
                    break;
                }
            }
            
            if (needStrengthening) {
                // Find the optimal position to apply Timar
                int bestPos = max(i, i + m - k);
                for (int j = bestPos; j < bestPos + k && j < n; j++) {
                    strengthened[j] = true;
                }
                result++;
            }
        }
        
        return result;
    }
};


#endif