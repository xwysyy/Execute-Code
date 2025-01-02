#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> freq;
        // Count frequency of each coin value
        for(int x : a) {
            freq[x]++;
        }
        
        // Find maximum frequency
        int maxFreq = 0;
        for(auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }
        
        return maxFreq;
    }
};


#endif