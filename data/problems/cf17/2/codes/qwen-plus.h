#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // If the difference in y-coordinates is less than the difference in x-coordinates, it's impossible
        if (d - b < a - c)
            return -1;
        
        // If the parity of the sum of coordinates is different, it's impossible
        if ((a + b) % 2 != (c + d) % 2)
            return -1;
        
        // Calculate the minimum number of moves required
        int diffX = c - a;
        int diffY = d - b;
        if (diffX >= 0 && diffY >= 0) {
            return max(diffX, diffY);
        } else {
            return abs(diffX) + abs(diffY - diffX) / 2;
        }
    }
};


#endif