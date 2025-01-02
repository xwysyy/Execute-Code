#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, string &s) {   
        int min_time = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                int time_to_green = n;
                for (int j = i; j < n; j++) {
                    if (s[j] == 'g') {
                        time_to_green = j - i;
                        break;
                    }
                }
                for (int j = 0; j < i; j++) {
                    if (s[j] == 'g') {
                        time_to_green = min(time_to_green, n - i + j);
                        break;
                    }
                }
                min_time = min(min_time, time_to_green);
            }
        }
        return min_time;
    }
};

#endif