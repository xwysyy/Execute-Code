#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        vector<int> sorted_a = a;
        sort(sorted_a.begin(), sorted_a.end());
        int max_count = 1, current_count = 1;
        
        for (int i = 1; i < n; ++i) {
            if (sorted_a[i] == sorted_a[i - 1]) {
                current_count++;
                max_count = max(max_count, current_count);
            } else {
                current_count = 1;
            }
        }
        
        return max(max_count, (n + 1) / 2);
    }
};

#endif