#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // Calculate the differences in x and y coordinates
        int dx = c - a; // difference in x
        int dy = d - b; // difference in y

        // The necessary condition to reach (c, d):
        // We want to be able to form dx = steps_right - steps_left
        // and dy = steps_right (since for every right move we increase y by 1)

        // Let steps_right = s, steps_left = t
        // We have:
        // dx = s - t
        // dy = s
        // Therefore, we can express t as:
        // t = s - dx  => s = dx + t
        // Plugging s into dy gives us:
        // dy = dx + t

        // Hence, we can express t in terms of dy and dx:
        // t = dy - dx
        // Thus:
        // t = (dy - dx) must be >= 0 and must have same parity as dx + dy to have a valid configuration.

        int steps_left = dy - dx; // possible steps to the left
        if (steps_left < 0 || (steps_left % 2 != 0) || (dy < 0)) {
            return -1;
        }

        // The total steps needed is just how much we need to move in y
        // since each diagonal move reduces the gap towards the target
        return dy + dx;
    }
};


#endif