#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, string &s) {
        vector<int> next_green(n);
        int last_green = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'g') {
                last_green = i;
            }
            next_green[i] = last_green;
        }
        int max_wait = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                int wait_time;
                if (next_green[i] == -1) {
                    int next_occurence = -1;
                    for (int j = 0; j < n; j++) {
                        if (s[j] == 'g') {
                            next_occurence = j;
                            break;
                        }
                    }
                    wait_time = (n - i + next_occurence) % n;
                     if(wait_time == 0) wait_time = n;
                }
                else
                 wait_time = (next_green[i] - i + n) % n;
                max_wait = max(max_wait, wait_time);
            }
        }
        return max_wait;
    }
};


#endif