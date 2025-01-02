#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Check if we can start from (1, 1) and end at (2, n)
        bool can_reach_top = (s1[0] == '0');       // Can we reach the first cell of first row?
        bool can_reach_bottom = false;             // Starting from second row is impossible.
        
        for(int i = 0; i < n; i++) {
            bool next_can_reach_top = false;
            bool next_can_reach_bottom = false;
            
            if (can_reach_top && s1[i] == '0') {
                next_can_reach_top = true;         // Stay on the top row in the same column
            }
            
            if (can_reach_bottom && s2[i] == '0') {
                next_can_reach_bottom = true;      // Stay on the bottom row in the same column
            }
            
            if (can_reach_top && s2[i] == '0') {
                next_can_reach_bottom = true;      // Move from top row to the bottom row
            }
            
            if (can_reach_bottom && s1[i] == '0') {
                next_can_reach_top = true;         // Move from bottom row to the top row
            }
            
            can_reach_top = next_can_reach_top;
            can_reach_bottom = next_can_reach_bottom;
        }
        
        // At the end, check if reaching (2, n) is possible, which would mean 
        // we successfully reached the last cell on the second row.
        return can_reach_bottom ? "YES" : "NO";
    }
};


#endif