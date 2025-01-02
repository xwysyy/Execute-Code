#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, std::string &s) {
        int max_wait_time = 0;
        
        // We will "flatten" the infinite cycle to two cycles, which should cover any starting point.
        std::string doubled_s = s + s;
        
        // Iterate over all potential start times (for each occurrence of the 'c')
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                // For each occurrence, determine the minimum i where the traffic light is green
                int wait_time = 0;
                for (int j = i; j < i + n; ++j) {
                    if (doubled_s[j] == 'g') {
                        wait_time = j - i;
                        break;
                    }
                }
                // Update the maximum guarantee wait time
                max_wait_time = std::max(max_wait_time, wait_time);
            }
        }
        
        return max_wait_time;
    }
};


#endif