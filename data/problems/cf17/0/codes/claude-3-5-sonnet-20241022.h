#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &a, int &b, int &c, int &d) {
        // If target y is less than start y, it's impossible
        if (d < b) return -1;
        
        // Calculate vertical distance
        int dy = d - b;
        
        // Calculate the maximum rightward movement possible with dy diagonal moves
        int max_right = a + dy;
        
        // Calculate the minimum rightward position possible
        int min_right = a - (dy + 1000000); // Large enough number to cover all cases
        
        // Check if target x is reachable
        if (c > max_right || c < min_right) return -1;
        
        // Calculate minimum moves needed
        int diagonal_moves = dy;  // Must move up dy times diagonally
        int horizontal_moves = max_right - c;  // Left moves needed after diagonal moves
        
        return diagonal_moves + horizontal_moves;
    }
};


#endif