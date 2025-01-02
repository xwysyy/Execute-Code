#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Create a map to store frequency of possible sums
        map<int, int> freq;
        
        // For each position i, try all possible values from 1 to n
        // and count how many times each resulting sum appears
        for (int i = 0; i < n; i++) {
            // For current position, try adding each value from 1 to n
            for (int j = 1; j <= n; j++) {
                freq[a[i] + j]++;
            }
        }
        
        // Find the maximum possible frequency
        int maxFreq = 0;
        for (auto &p : freq) {
            // For each sum, we can only use each permutation value once
            // So we need to take minimum of frequency and n
            maxFreq = max(maxFreq, min(p.second, n));
        }
        
        return maxFreq;
    }
};


#endif