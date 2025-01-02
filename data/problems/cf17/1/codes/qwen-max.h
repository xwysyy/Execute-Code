#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // Calculate the horizontal and vertical distances
        int dx = c - a;
        int dy = d - b;

        // If the vertical distance is less than 0, it's impossible to reach the target
        if (dy < 0) {
            return -1;
        }

        // The number of moves to the top right (x+1, y+1) must be equal to the vertical distance
        int topRightMoves = dy;

        // After making topRightMoves, the new x-coordinate will be a + topRightMoves
        int newX = a + topRightMoves;

        // If the new x-coordinate is greater than the target x-coordinate, we need to move left
        int leftMoves = newX > c ? newX - c : 0;

        // The total number of moves is the sum of topRightMoves and leftMoves
        int totalMoves = topRightMoves + leftMoves;

        // Check if the final position matches the target
        if (newX - leftMoves == c && b + topRightMoves == d) {
            return totalMoves;
        } else {
            return -1;
        }
    }
};

#endif