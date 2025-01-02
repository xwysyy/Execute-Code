#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<long long, int> prefix_sum_index;
        long long sum = 0;
        int max_segments = 0;
        prefix_sum_index[0] = -1; // To handle the case when a beautiful segment starts from index 0
        
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (prefix_sum_index.find(sum) != prefix_sum_index.end()) {
                // If the same sum is found, it means there is a beautiful segment
                int prev_index = prefix_sum_index[sum];
                max_segments = max(max_segments, 1 + (prev_index >= 0 ? prefix_sum_index[sum] + 1 : 0));
            }
            // Update the latest index of this sum
            prefix_sum_index[sum] = i;
        }
        
        return max_segments;
    }
};

#endif