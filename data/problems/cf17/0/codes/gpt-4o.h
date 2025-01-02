#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // Impossible move condition
        if (d < b) {
            return -1;
        }
        
        // Calculate the required changes
        int deltaY = d - b;
        
        // Compare a with respect to desired x-coordinate adjustments
        int min_x_c = a + deltaY;
        
        if (min_x_c > c) {
            // Need additional left moves
            return deltaY + (min_x_c - c);
        } else if (min_x_c == c) {
            // Exact diagonal moves suffices
            return deltaY;
        } else {
            // Impossible since we're not allowed to move right except diagonally
            return -1;
        }
    }
};


#endif