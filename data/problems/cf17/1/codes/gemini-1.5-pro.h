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
        if (b == d) {
            if (a == c)
                return 0;
            else if (a > c)
                return a - c;
            else
                return -1;
        }
        int right_moves = d - b;
        int current_x = a + right_moves;
        if (current_x == c)
            return right_moves;
        else if (current_x > c)
            return right_moves + current_x - c;
        else
            return -1;
    }
};


#endif