#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // This will keep track of whether we can reach the end
        bool canReach = false; 
        
        // Start from (1, 1) which corresponds to (0, 0) in 0-indexed terms.
        int row = 0, col = 0;
        
        // The process will continue until we either reach the end or run out of columns.
        while (col < n) {
            // If we are in row 0 (first row)
            if (row == 0) {
                // If the arrow points to the right, move right
                if (s1[col] == '>') {
                    col++; // Move to the right
                } else {
                    // If the arrow points to the left, we cannot go back into column -1
                    if (col > 0) {
                        col--; // Move to the left
                    }
                    // We will switch to row 1 (second row) if we are at the leftmost side
                    row = 1; // Move down to row 2
                }
            } else {
                // If we are in row 1 (second row)
                if (s2[col] == '>') {
                    col++; // Move to the right
                } else {
                    // Left arrow in second row, ensure we do not go out of bounds
                    if (col > 0) {
                        col--; // Move to the left
                    }
                    // Switch to row 0 (first row)
                    row = 0; // Move up to row 1
                }
            }
            
            // Check if we have reached cell (2, n), which is (1, n-1) in 0-indexing
            if (row == 1 && col == n - 1) {
                canReach = true; // We can reach cell (2, n)
                break; // Exit loop
            }
        }
        
        return canReach ? "YES" : "NO"; // Return the result
    }
};


#endif