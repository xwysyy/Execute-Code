#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &a, int &b, int &c, int &d) {
        if (b > d)
            return -1;
        if (a == c && b == d)
            return 0;
        int right_moves = d - b;
        int diff = c - a;
        if (diff == right_moves)
            return right_moves;
        if (diff > right_moves)
            return -1;

        int left_moves = right_moves - diff;
        return right_moves + left_moves;

    }
};


#endif