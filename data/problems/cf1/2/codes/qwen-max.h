#ifndef QWEN_MAX_H
#define QWEN_MAX_H
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
        for (auto &it : freq) {
            maxFreq = max(maxFreq, it.second);
        }
        
        return maxFreq;
    }
};

#endif