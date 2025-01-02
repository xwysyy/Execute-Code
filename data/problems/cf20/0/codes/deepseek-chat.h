#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {
        int max_entertainment = -1;
        int result = -1;
        int skip_time = 0; // Time taken to skip to the current video

        for (int i = 0; i < n; ++i) {
            // Total time to watch the current video: skip_time + a[i]
            if (skip_time + a[i] <= t) {
                if (b[i] > max_entertainment) {
                    max_entertainment = b[i];
                    result = i + 1; // Video indices are 1-based
                }
            }
            // Increment skip_time by 1 second for the next video
            skip_time += 1;
        }

        return result;
    }
};


#endif