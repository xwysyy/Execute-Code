#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::string &s) {
        bool can_clockwise = false;
        bool can_anticlockwise = false;
        
        // Check the entire string for conditions
        for (int i = 0; i < n; ++i) {
            if (s[i] == '-') {
                // This section lets us know that it is returnable directly
                can_clockwise = true;
                can_anticlockwise = true;
            } else if (s[i] == '>') {
                can_clockwise = true;
            } else if (s[i] == '<') {
                can_anticlockwise = true;
            }
        }
        
        // If the belt system allows a full loop in one direction
        if (can_clockwise && can_anticlockwise) {
            return n;
        }
        
        int returnable_count = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '-' ||
                (s[i] == '>' && can_clockwise) || 
                (s[i] == '<' && can_anticlockwise)) {
                ++returnable_count;
            }
        }
        
        return returnable_count;
    }
};


#endif