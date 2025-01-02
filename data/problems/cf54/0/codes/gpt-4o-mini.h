#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> prefix_sum_index; // Maps prefix sums to their latest index
        int prefix_sum = 0;
        int count_segments = 0;
        int last_index = -1; // Last index where we counted a beautiful segment

        prefix_sum_index[0] = -1; // To handle the case where entire prefix sums to zero

        for (int i = 0; i < n; i++) {
            prefix_sum += a[i];

            if (prefix_sum_index.find(prefix_sum) != prefix_sum_index.end()) {
                int last_position = prefix_sum_index[prefix_sum];
                
                // Check if the current segment is non-overlapping
                if (last_position >= last_index) {
                    count_segments++;
                    last_index = i; // Update last index to the current position
                }
            }
            
            // Update the latest index of this prefix sum
            prefix_sum_index[prefix_sum] = i;
        }

        return count_segments;
    }
};


#endif