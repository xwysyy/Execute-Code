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
        prefix_sum_index[0] = -1; // To handle the case where a segment starts from index 0
        
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (prefix_sum_index.find(sum) != prefix_sum_index.end()) {
                // If the same sum is found, it means there is a zero-sum subarray
                max_segments++;
                // Reset the sum and map to start looking for new segments
                prefix_sum_index.clear();
                prefix_sum_index[0] = -1;
                sum = 0;
            } else {
                // Store the first occurrence of this sum
                prefix_sum_index[sum] = i;
            }
        }
        
        return max_segments;
    }
};

#endif