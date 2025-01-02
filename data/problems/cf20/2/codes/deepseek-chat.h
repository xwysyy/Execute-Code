#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {
        int max_entertainment = -1;
        int result = -1;
        for (int i = 0; i < n; ++i) {
            // Time to reach the i-th video is i seconds (since each skip takes 1 second)
            int total_time = i + a[i];
            if (total_time <= t && b[i] > max_entertainment) {
                max_entertainment = b[i];
                result = i + 1; // Video indices are 1-based
            }
        }
        return result;
    }
};


#endif