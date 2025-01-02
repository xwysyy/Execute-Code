#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {   
        // Create a frequency array to count occurrences
        int count[1001] = {0};
        
        for (int num : a) {
            count[num]++;
        }
        
        // Find the minimum and maximum values with non-zero counts
        int min_value = 1001, max_value = -1;
        for (int i = 1; i <= 1000; ++i) {
            if (count[i] > 0) {
                min_value = std::min(min_value, i);
                max_value = std::max(max_value, i);
            }
        }
        
        // Calculate the maximum possible cost based on min and max
        int max_cost = (max_value - min_value) * 2; // Since two colors can be used between min and max values
        
        return max_cost;
    }
};


#endif