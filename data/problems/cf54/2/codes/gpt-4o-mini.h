#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> prefix_sum_map;  // Maps prefix sum to the last index it occurs
        int prefix_sum = 0;  // The current prefix sum
        int count = 0;  // Count of non-overlapping segments
        int last_end_index = -1;  // The last index of the end of a found segment

        // Initialize the map with the prefix sum of 0 at index -1 (before any elements)
        prefix_sum_map[0] = -1;

        for (int i = 0; i < n; i++) {
            prefix_sum += a[i];  // Update the current prefix sum
            
            // Check if this prefix sum has been seen before
            if (prefix_sum_map.find(prefix_sum) != prefix_sum_map.end()) {
                // Get the last index where this prefix sum occurred
                int last_index = prefix_sum_map[prefix_sum];

                // If the last index is greater than last_end_index, we can count this segment
                if (last_index >= last_end_index) {
                    count++;  // We found a new non-overlapping beautiful segment
                    last_end_index = i;  // Update the last end index to current index
                }
            }
            
            // Update the map with the current prefix sum index
            prefix_sum_map[prefix_sum] = i;
        }

        return count;  // Return the count of non-overlapping segments
    }
};


#endif