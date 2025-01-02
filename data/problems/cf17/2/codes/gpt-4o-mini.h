#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        int dx = c - a; // difference in x
        int dy = d - b; // difference in y

        // It's impossible if we need to move down in y while needing to move up in y
        if (dy < 0 || dy < dx) {
            return -1;
        }
        
        // Calculating minimum moves
        return 2 * dy - dx;
    }
};


#endif