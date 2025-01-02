#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {   
        std::unordered_map<int, int> frequencyMap;
        
        // Calculate frequency of each coin value
        for(int i = 0; i < n; ++i) {
            frequencyMap[a[i]]++;
        }
        
        // Find the maximum frequency
        int maxFrequency = 0;
        for(const auto& entry : frequencyMap) {
            maxFrequency = std::max(maxFrequency, entry.second);
        }
        
        // The minimum number of pockets needed is the maximum frequency
        return maxFrequency;
    }
};


#endif