#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        unordered_map<int, int> freq;
        int maxFreq = 0;
        
        // Count the frequency of each coin value
        for (int i = 0; i < n; ++i) {
            freq[a[i]]++;
            maxFreq = max(maxFreq, freq[a[i]]);
        }
        
        // The minimum number of pockets needed is equal to the maximum frequency of any coin value
        return maxFreq;
    }
};


#endif