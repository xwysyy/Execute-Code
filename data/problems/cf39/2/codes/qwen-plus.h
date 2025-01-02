#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {   
        // Initialize positions
        int row = 1, col = 1;
        
        // Check if we can reach (2, n)
        for (int step = 0; step < 2 * n; ++step) {
            // Move according to the arrow direction
            if (row == 1) {
                if (s1[col - 1] == '>') col = min(col + 1, n);
                else col = max(col - 1, 1);
            } else {
                if (s2[col - 1] == '>') col = min(col + 1, n);
                else col = max(col - 1, 1);
            }

            // Switch rows after moving
            row = 3 - row;

            // Check if we reached the target position
            if (row == 2 && col == n) return "YES";

            // If we are stuck in the first column of the first row, it's impossible to reach (2, n)
            if (col == 1 && row == 1) return "NO";
        }

        return "NO";
    }
};


#endif