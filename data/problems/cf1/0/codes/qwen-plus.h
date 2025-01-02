#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            freq[a[i]]++;
        }
        
        int maxFreq = 0;
        for (auto &entry : freq) {
            maxFreq = max(maxFreq, entry.second);
        }
        
        return maxFreq;
    }
};


#endif