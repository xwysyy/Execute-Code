#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        // If all conveyor belts are in the same direction (either all '>' or all '<'),
        // then no room is returnable because snakes cannot come back to their original room.
        // Otherwise, all rooms are returnable.
        bool allClockwise = true, allAnticlockwise = true;
        for (char c : s) {
            if (c != '>') allClockwise = false;
            if (c != '<') allAnticlockwise = false;
        }
        
        if (allClockwise || allAnticlockwise) {
            return 0;
        } else {
            return n;
        }
    }
};


#endif