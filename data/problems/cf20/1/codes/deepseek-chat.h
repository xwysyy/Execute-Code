#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {
        int max_entertainment = -1;
        int result_index = -1;
        
        for (int i = 0; i < n; ++i) {
            // Calculate the total time to reach and watch the i-th video
            int total_time = i + a[i];
            if (total_time <= t) {
                // If the video can be watched within the time limit
                if (b[i] > max_entertainment) {
                    max_entertainment = b[i];
                    result_index = i + 1; // +1 because videos are indexed from 1
                }
            }
        }
        
        return result_index;
    }
};


#endif