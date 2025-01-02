#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Create a map to store the frequency of possible sums
        map<int, int> freq;
        
        // For each element in array
        for(int i = 0; i < n; i++) {
            // Try all possible values that can be obtained by adding numbers from 1 to n
            // a[i] + j where j goes from 1 to n
            for(int j = 1; j <= n; j++) {
                freq[a[i] + j]++;
            }
        }
        
        // Find the maximum frequency
        int maxFreq = 0;
        for(auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }
        
        return maxFreq;
    }
};


#endif