#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {   
        std::unordered_map<int, int> frequency_map;
        
        // Populate the frequency map with counts of each element
        for (int num : a) {
            frequency_map[num]++;
        }

        int result = -1;
        
        // Find the minimum element that appears at least three times
        for (auto it : frequency_map) {
            if (it.second >= 3) {
                if (result == -1 || it.first < result) {
                    result = it.first;
                }
            }
        }
        
        return result;
    }
};


#endif