#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        int dx = c - a;
        int dy = d - b;

        // We can't have dy being larger than dx because
        // each diagonal move changes both x and y by 1.
        if (dy > dx) {
            return -1;
        }

        // If dx - dy is odd, it's impossible to reach since
        // we can't adjust with only these two types of moves.
        if ((dx - dy) % 2 != 0) {
            return -1;
        }

        // The minimum moves needed is dx because:
        // - dy diagonal moves to match the d,
        // - dx-dy left moves to correct back the x.
        return dx;
    }
};


#endif