#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, string &s) {
        // Initialize the minimum time to a large value
        int min_time = n + 1; // The maximum will be n seconds if we want guaranteed
        // Iterate through the string to find the next occurrence of 'g'
        for (int i = 0; i < n; i++) {
            if (s[i] == 'g') {
                // Calculate how long it takes to reach this 'g' color
                // If current color is at index c_index derived from character `c`
                int c_index = (find(s.begin(), s.end(), c) - s.begin());
                // Calculate the time difference
                int time_difference = (i - c_index + n) % n;
                // Ensure time_difference is in positive mod
                min_time = min(min_time, time_difference == 0 ? n : time_difference);
            }
        }
        return min_time;
    }
};


#endif