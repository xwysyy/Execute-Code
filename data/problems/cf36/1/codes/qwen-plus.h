#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            // Calculate the frequency of each (a[i] - i) % n value.
            // This is because adding a permutation p_i to a[i] will result in values that have the same remainder when divided by n.
            freq[(a[i] - i - 1 + n) % n]++;
        }
        
        int maxFreq = 0;
        for (const auto& entry : freq) {
            maxFreq = max(maxFreq, entry.second);
        }
        
        return maxFreq + 1;
    }
};


#endif