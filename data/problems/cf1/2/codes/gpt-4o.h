#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {   
        // Map to count the frequency of each coin value
        std::unordered_map<int, int> frequency;
        
        // Populate the frequency map
        for (int i = 0; i < n; i++) {
            frequency[a[i]]++;
        }
        
        // Find the maximum frequency
        int maxFrequency = 0;
        for (const auto& pair : frequency) {
            maxFrequency = std::max(maxFrequency, pair.second);
        }
        
        // The result is the maximum frequency
        return maxFrequency;
    }
};


#endif