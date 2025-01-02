#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        if (b > d) return -1;
        if (a == c && b == d) return 0;
        int diff_x = c - a;
        int diff_y = d - b;
        if (diff_x == diff_y) return diff_y;
        if (diff_x < diff_y)
        {
            int left_moves = diff_y - diff_x;
            if (a - left_moves < c) return -1;
            return diff_y + left_moves;
        } else
            return -1;
    }
};


#endif