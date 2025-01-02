#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        unordered_map<long long, int> freq;
        int maxFreq = 0;
        
        for (int i = 0; i < n; ++i) {
            // Check for the case when we add permutation values from 1 to n
            for (int j = 1; j <= min(n, 200); ++j) {
                maxFreq = max(maxFreq, ++freq[a[i] + j]);
            }
            // Check for the case when we add 0 (essentially not changing the value)
            maxFreq = max(maxFreq, ++freq[a[i]]);
        }
        
        return maxFreq;
    }
};


#endif