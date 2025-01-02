#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {   
        int row = 0, col = 0; // Start at (1,1), which is (0,0) in 0-based index.
        
        while (true) {
            if (row == 0) { // Row 1
                if (s1[col] == '>') {
                    if (col + 1 < n) {
                        col++;
                    } else {
                        return "NO"; // Can't move right anymore
                    }
                } else {
                    if (col > 0) {
                        col--;
                    } else {
                        return "NO"; // Can't move left from (1,1)
                    }
                }
                // Move down to row 2 after adjusting to the arrow.
                row = 1;
            } else { // Row 2
                if (col == n - 1) { // Check if it's the last column
                    return "YES";   // Successfully reached (2, n)
                }
                if (s2[col] == '>') {
                    if (col + 1 < n) {
                        col++;
                    } else {
                        return "NO"; // Can't move right anymore
                    }
                } else {
                    if (col > 0) {
                        col--;
                    } else {
                        return "NO"; // Nowhere to go left
                    }
                }
                // Move up to row 1 after adjusting to the arrow.
                row = 0;
            }
        }
    }
};


#endif