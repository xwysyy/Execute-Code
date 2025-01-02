#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        unordered_map<int, int> prefix_sum_indices;
        prefix_sum_indices[0] = -1;
        int prefix_sum = 0;
        int max_beautiful_segments = 0;
        int last_end_index = -1;

        for (int i = 0; i < n; ++i) {
            prefix_sum += a[i];
            if (prefix_sum_indices.find(prefix_sum) != prefix_sum_indices.end()) {
                if (prefix_sum_indices[prefix_sum] >= last_end_index) {
                    max_beautiful_segments++;
                    last_end_index = i;
                }
            }
            prefix_sum_indices[prefix_sum] = i;
        }

        return max_beautiful_segments;
    }
};


#endif