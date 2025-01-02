#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {   
        int best_index = -1;
        int max_entertainment = 0;
        
        for (int i = 0; i < n; ++i) {
            int time_to_watch = i + a[i]; // Time to skip to the video and watch it
            if (time_to_watch <= t && b[i] > max_entertainment) {
                max_entertainment = b[i];
                best_index = i + 1; // Convert to 1-based index
            }
        }
        
        return best_index;
    }
};

#endif