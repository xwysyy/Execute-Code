#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {   
        int row = 0, col = 0;
        while (true) {
            if (row == 1 && col == n - 1) return "YES";
            
            // Move the robot
            if (row == 0) {
                if (s1[col] == '>') col++;
                else col--;
            } else {
                if (s2[col] == '>') col++;
                else col--;
            }
            
            // Ensure the robot doesn't go out of bounds
            if (col < 0 || col >= n) return "NO";
            
            // Move the robot along the arrow
            if (row == 0) {
                if (s1[col] == '>') col++;
                else col--;
            } else {
                if (s2[col] == '>') col++;
                else col--;
            }
            
            // Ensure the robot doesn't go out of bounds
            if (col < 0 || col >= n) return "NO";
            
            // Move the robot down
            if (row == 0) row = 1;
            else row = 0;
        }
        return "NO";
    }
};

#endif