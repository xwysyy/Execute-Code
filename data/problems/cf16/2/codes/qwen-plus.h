#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        // Calculate the absolute distance in both dimensions
        int dx = abs(a);
        int dy = abs(b);

        // The king can move diagonally by alternating moves, effectively moving 1 step closer in both x and y per two moves
        int diagonal_moves = min(dx, dy);
        int remaining_x = dx - diagonal_moves;
        int remaining_y = dy - diagonal_moves;

        // Total time is the sum of diagonal moves (each counting as 2 moves) plus remaining moves plus any necessary skips
        int total_time = 2 * diagonal_moves + remaining_x + remaining_y;

        // If both remaining_x and remaining_y are 0 but we have an odd number of diagonal moves, we need one extra skip move
        if (diagonal_moves > 0 && (remaining_x == 0 && remaining_y == 0) && (diagonal_moves % 2 != 0)) {
            total_time++;
        }

        // If there's only one remaining move in either dimension and the diagonal moves are even, we need one extra skip move
        if ((remaining_x == 1 || remaining_y == 1) && (diagonal_moves % 2 == 0)) {
            total_time++;
        }

        return total_time;
    }
};


#endif