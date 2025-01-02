#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // If the difference between the y-coordinates is greater than the difference between the x-coordinates,
        // or if (c-a) + (d-b) is odd, it's impossible to reach (c,d) from (a,b)
        if ((d - b) > (c - a) || ((c - a - d + b) % 2 != 0)) {
            return -1;
        }
        // The minimum number of moves required is the maximum of the absolute differences in x and y coordinates
        return max(abs(c - a), abs(d - b));
    }
};


#endif