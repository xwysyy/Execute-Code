#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        // Frequency map to count occurrences of each number
        std::unordered_map<int, int> frequency_map;
        
        // Populate the frequency map
        for (int num : a) {
            frequency_map[num]++;
        }
        
        // Variable to track the minimum value that appears at least three times
        int min_value = INT_MAX;
        
        // Iterate over the frequency map to find the minimum value with at least 3 occurrences
        for (const auto &entry : frequency_map) {
            if (entry.second >= 3) {
                min_value = std::min(min_value, entry.first);
            }
        }
        
        // If min_value hasn't been updated, return -1 meaning no element has 3 or more occurrences
        return (min_value == INT_MAX) ? -1 : min_value;
    }
};


#endif