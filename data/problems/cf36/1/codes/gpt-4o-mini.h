#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<long long, int> frequencyMap;
        
        for (int i = 0; i < n; ++i) {
            // Calculate new value after permutation addition
            long long newValue = a[i] + (i + 1);
            frequencyMap[newValue]++;
        }
        
        // Find the maximum frequency
        int maxFrequency = 0;
        for (const auto &entry : frequencyMap) {
            if (entry.second > maxFrequency) {
                maxFrequency = entry.second;
            }
        }
        
        return maxFrequency;
    }
};


#endif