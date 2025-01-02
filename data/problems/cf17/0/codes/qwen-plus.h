#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // Calculate the differences
        int diffX = c - a;
        int diffY = d - b;

        // If the parity of the differences is different, it's impossible to reach (c, d)
        if ((diffX + diffY) % 2 != 0) {
            return -1;
        }

        // If diffY is greater than diffX, it's also impossible since we can't increase y faster than x
        if (diffY < diffX) {
            return -1;
        }

        // The minimum number of moves required
        return abs(diffX) + abs(diffY - diffX);
    }
};


#endif