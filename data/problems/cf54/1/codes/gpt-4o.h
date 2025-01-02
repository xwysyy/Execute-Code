#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        unordered_map<int, int> sum_map;
        int prefix_sum = 0;
        int count = 0;
        int last_end = -1;

        sum_map[0] = -1; // to handle the case when the first segment is a zero sum from the start
        
        for (int i = 0; i < n; ++i) {
            prefix_sum += a[i];

            // Check if this prefix sum has been seen before
            if (sum_map.find(prefix_sum) != sum_map.end()) {
                int previous_index = sum_map[prefix_sum];
                // Ensure non-overlapping
                if (previous_index >= last_end) {
                    count++;
                    last_end = i;
                }
            }
            
            // Update the map with the current index of the prefix sum
            sum_map[prefix_sum] = i;
        }

        return count;
    }
};


#endif