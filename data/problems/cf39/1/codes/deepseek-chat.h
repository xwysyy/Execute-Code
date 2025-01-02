#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // The robot starts at (1, 1)
        int row = 1;
        int col = 1;
        
        // We need to reach (2, n)
        while (col < n) {
            // First, the robot moves left, right, down, or up
            // Since it can't go outside the grid, we need to check boundaries
            // Let's try moving right first
            if (col < n) {
                col++;
            } else {
                // If it can't move right, try moving down
                if (row == 1) {
                    row++;
                } else {
                    // If it can't move down, try moving up
                    row--;
                }
            }
            
            // Then, move along the arrow in the current cell
            if (row == 1) {
                if (s1[col - 1] == '>') {
                    col++;
                } else {
                    col--;
                }
            } else {
                if (s2[col - 1] == '>') {
                    col++;
                } else {
                    col--;
                }
            }
            
            // If the robot reaches (2, n), return "YES"
            if (row == 2 && col == n) {
                return "YES";
            }
        }
        
        // If the loop ends without reaching (2, n), return "NO"
        return "NO";
    }
};


#endif