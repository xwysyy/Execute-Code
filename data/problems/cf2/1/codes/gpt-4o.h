#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        bool has_bidirectional = false;
        bool all_clockwise = true;
        bool all_anticlockwise = true;
        
        // Check each belt's state
        for (char c : s) {
            if (c == '-') {
                has_bidirectional = true;
            }
            if (c == '>') {
                all_anticlockwise = false;
            }
            if (c == '<') {
                all_clockwise = false;
            }
        }
        
        // If there is any '-' or all are '>' or all are '<', they are all returnable
        if (has_bidirectional || all_clockwise || all_anticlockwise) {
            return n;
        }
        
        // Otherwise, the number of `-` provides the answer
        int returnable_rooms = 0;
        
        for (int i = 0; i < n; ++i) {
            // The room is returnable if the rope connecting to the next room can
            // go both ways (i.e., `'-'`) or this room is a start or end of unidirectional
            if (s[i] == '-' || s[(i - 1 + n) % n] == '-') {
                returnable_rooms++;
            }
        }
        
        return returnable_rooms;
    }
};


#endif