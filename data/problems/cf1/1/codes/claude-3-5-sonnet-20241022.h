#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Count frequency of each coin value
        unordered_map<int, int> freq;
        for(int x : a) {
            freq[x]++;
        }
        
        // Find the maximum frequency
        int maxFreq = 0;
        for(auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }
        
        // We need at least maxFreq pockets
        return maxFreq;
    }
};


#endif