#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // Calculate the horizontal and vertical distances
        int dx = c - a;
        int dy = d - b;

        // If the vertical distance is less than 0, it's impossible to reach the target
        if (dy < 0) {
            return -1;
        }

        // If the horizontal distance is greater than the vertical distance, it's impossible to reach the target
        if (dx > dy) {
            return -1;
        }

        // The minimum number of moves is the sum of the absolute horizontal and vertical distances
        return dx + dy;
    }
};

#endif