#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        unordered_map<int, int> prefix_sum_indices;
        int sum = 0;
        int beautiful_segments = 0;
        int last_end_index = -1;
        prefix_sum_indices[0] = -1;

        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (prefix_sum_indices.find(sum) != prefix_sum_indices.end()) {
                if (prefix_sum_indices[sum] >= last_end_index) {
                    beautiful_segments++;
                    last_end_index = i;
                }
            }
            prefix_sum_indices[sum] = i;
        }

        return beautiful_segments;
    }
};


#endif