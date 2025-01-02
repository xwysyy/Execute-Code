#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // Calculate distance in terms of x and y
        int deltaX = c - a;
        int deltaY = d - b;

        // The possible moves affect the distance differently
        // Moving to (x+1, y+1) increases both x and y by 1
        // Moving to (x-1, y) decreases x by 1 only
        // We need to check the conditions based on the differences
        if (deltaY < 0) {
            // When the target y is below the starting y
            return -1;  // impossible as all moves increase y
        }

        // After reaching the same y level as d using (x+1, y+1) moves,
        // we'll need extra moves to adjust x because we can adjust x only by moving left.
        int totalMoves = 0;

        // Go to the target y level with upwards diagonal moves
        totalMoves += deltaY;

        // After reaching (x, d), we have:
        // new deltaX must be how far we need to walk horizontally
        // deltaX can be adjusted by deltaY moves made upwards:
        // if we have moved up deltaY times, we can move to the right deltaY times (all at y level d).
        int horizontalMoves = abs(deltaX) - deltaY;

        // In the end, we need at least 'horizontalMoves' which cannot be negative
        // If horizontalMoves is odd, we cannot land exactly on c
        if (horizontalMoves < 0 || horizontalMoves % 2 != 0) {
            return -1;
        }
        
        totalMoves += horizontalMoves;  // add horizontal adjustment moves

        return totalMoves;
    }
};


#endif