#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, string &s) {   
        int max_time = 0;
        int current_time = 0;
        bool found_current_color = false;

        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                found_current_color = true;
                current_time = 0;
            } else if (found_current_color && s[i] == 'g') {
                max_time = std::max(max_time, current_time);
                found_current_color = false;
            } else if (found_current_color) {
                current_time++;
            }
        }

        // If the current color is not found again, we need to consider the wrap-around
        if (found_current_color) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'g') {
                    max_time = std::max(max_time, current_time + i);
                    break;
                }
                current_time++;
            }
        }

        return max_time;
    }
};

#endif