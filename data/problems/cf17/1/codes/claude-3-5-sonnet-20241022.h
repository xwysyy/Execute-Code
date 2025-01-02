#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // If target y is less than start y, impossible
        if (d < b) return -1;
        
        // Calculate vertical distance needed
        int verticalDist = d - b;
        
        // Calculate the maximum x-coordinate reachable with vertical moves
        int maxX = a + verticalDist;
        
        // If target x is greater than max possible x, impossible
        if (c > maxX) return -1;
        
        // If target x is less than (start x - vertical distance), impossible
        // Because we can only go left by using extra moves to compensate diagonal moves
        if (c < a - verticalDist) return -1;
        
        // Calculate total moves needed:
        // verticalDist diagonal moves + extra left moves if needed
        int leftMoves = maxX - c;
        
        return verticalDist + leftMoves;
    }
};


#endif