#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Check if we can start and end
        if (s1[0] == '1' || s2[n - 1] == '1') {
            return "NO";
        }
        
        // Current positions where we can be: at column 1 we can start at row 1
        bool onRow1 = true; // If we are on row 1 at current column
        bool onRow2 = false; // If we are on row 2 at current column
        
        for (int j = 1; j < n; j++) {
            // We can determine where we can move to in the next column
            bool nextOnRow1 = false;
            bool nextOnRow2 = false;
            
            // Current positions allow movement to next column
            if (onRow1) {
                if (s1[j] == '0') {
                    nextOnRow1 = true; // Can stay on row 1
                }
                if (s2[j] == '0') {
                    nextOnRow2 = true; // Can move to row 2
                }
            }
            
            if (onRow2) {
                if (s2[j] == '0') {
                    nextOnRow2 = true; // Stay on row 2
                }
                if (s1[j] == '0') {
                    nextOnRow1 = true; // Move to row 1
                }
            }
            
            // Now we need to update positions for the next iteration
            onRow1 = nextOnRow1;
            onRow2 = nextOnRow2;
            
            // If we cannot be on either row for the next column, exit early
            if (!onRow1 && !onRow2) {
                return "NO";
            }
        }
        
        // We need to check if we can end up in row 2 at the last column
        return onRow2 ? "YES" : "NO";
    }
};


#endif