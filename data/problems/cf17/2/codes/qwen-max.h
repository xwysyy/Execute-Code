#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // Calculate the difference in x and y coordinates
        int dx = c - a;
        int dy = d - b;
        
        // If the difference in y is less than 0, it's impossible to reach the target
        if (dy < 0) {
            return -1;
        }
        
        // The number of moves required is the maximum of the difference in x and y
        // because each move can increase x by 1 and y by 1, or decrease x by 1
        int moves = max(dx, dy);
        
        // Check if the number of moves is even or odd
        // If the sum of the differences is odd, it's impossible to reach the target
        if ((dx + dy) % 2 != 0) {
            return -1;
        }
        
        return moves;
    }
};

#endif