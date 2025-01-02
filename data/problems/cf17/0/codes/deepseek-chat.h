#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // Calculate the differences in x and y coordinates
        int deltaX = c - a;
        int deltaY = d - b;
        
        // Check if it's possible to reach the target
        // Since each move changes x by +1 or -1 and y by +1 or 0,
        // the total change in y must be less than or equal to the total change in x
        if (deltaY > deltaX || deltaY < 0) {
            return -1;
        }
        
        // The number of moves is the maximum of deltaX and deltaY
        // Because each move can contribute to both x and y changes
        return std::max(deltaX, deltaY);
    }
};


#endif