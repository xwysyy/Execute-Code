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
            if (row == 0 && col == n - 1) return "NO"; // If we reach the end of the first row, we can't go down.
            
            // Move according to the arrow
            if (row == 0) {
                if (s1[col] == '>') col++;
                else col--;
            } else {
                if (s2[col] == '>') col++;
                else col--;
            }
            
            // Check if we need to move to the other row
            if (col == 0 || col == n - 1) {
                row = 1 - row; // Switch rows
            }
            
            // Check for out of bounds
            if (col < 0 || col >= n) return "NO";
        }
        return "NO";
    }
};

#endif