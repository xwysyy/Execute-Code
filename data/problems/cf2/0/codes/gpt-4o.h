#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        // Flag to check all belts are one-directional or bidirectional
        bool all_clockwise = true;
        bool all_counterclockwise = true;

        for (char c : s) {
            if (c == '>') all_counterclockwise = false; // Breaks counterclockwise flow
            if (c == '<') all_clockwise = false; // Breaks clockwise flow
            if (c == '-') return n; // Any bidirectional allows full access
        }

        // If all in one direction, return all rooms
        if (all_clockwise || all_counterclockwise) {
            return n;
        }

        // If neither is true and there is no `-`, find connected parts
        // For this problem case, this essentially means no returnable if only > or < in separate sections are there
        // But assuming the constraints for < and > isolated is solved by former cases
        return 0; // Since we would need a custom check for partial sections which are not possible due to full n in `>` or `<`
    }
};


#endif