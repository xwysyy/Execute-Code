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
        // The condition is that deltaY must be non-negative and deltaX + deltaY must be even
        if (deltaY < 0 || (deltaX + deltaY) % 2 != 0) {
            return -1;
        }
        
        // The minimum number of moves is the maximum of deltaY and (deltaX + deltaY) / 2
        return max(deltaY, (deltaX + deltaY) / 2);
    }
};


#endif