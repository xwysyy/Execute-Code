#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // Calculate the number of diagonal moves
        int neededDiagonalMoves = d - b;
        
        // If the target y is less than the start y, it's impossible
        if (d < b) return -1;

        // Calculate the required left moves
        int L = a + neededDiagonalMoves - c;
        
        // Check if the left moves needed are non-negative and feasible
        if (L < 0) return -1;

        // Total number of moves is sum of diagonal and left moves
        return neededDiagonalMoves + L;
    }
};


#endif