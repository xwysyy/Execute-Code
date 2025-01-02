#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // Calculate the differences in x and y coordinates
        int dx = c - a;
        int dy = d - b;
        
        // If the target y-coordinate is less than the initial y-coordinate, it's impossible
        if (dy < 0) {
            return -1;
        }
        
        // If the difference in x is greater than the difference in y, it's impossible
        if (dx > dy) {
            return -1;
        }
        
        // The number of moves is the difference in y-coordinates
        return dy;
    }
};


#endif