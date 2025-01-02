#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Start from the first cell (1,1), which means s1[0]
        // This implies we're at row 1 at the start
        bool canStayRow1 = (s1[0] == '0');
        bool canStayRow2 = false; // Row 2 cannot be accessed initially
        
        for (int i = 1; i < n; ++i) {
            bool nextCanStayRow1 = false;
            bool nextCanStayRow2 = false;
            
            // Check if we can stay in row 1
            if (s1[i] == '0') {
                if (canStayRow1) { // can we stay in row 1?
                    nextCanStayRow1 = true;
                }
                if (canStayRow2) { // move from row 2 to row 1
                    nextCanStayRow1 = true;
                }
            }
            
            // Check if we can stay in row 2
            if (s2[i] == '0') {
                if (canStayRow2) { // can we stay in row 2?
                    nextCanStayRow2 = true;
                }
                if (canStayRow1) { // move from row 1 to row 2
                    nextCanStayRow2 = true;
                }
            }
            
            // Update for the next iteration
            canStayRow1 = nextCanStayRow1;
            canStayRow2 = nextCanStayRow2;
        }
        
        // We can successfully reach (2,n) if we can stay in row 2 at the last column
        return canStayRow2 ? "YES" : "NO";
    }
};


#endif