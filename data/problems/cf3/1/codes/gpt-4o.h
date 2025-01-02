#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::string solve(int &n, std::string &s1, std::string &s2) {
        // Start at top-left corner (0,0) in zero-index notation
        int currentRow = 0;
        
        for (int i = 0; i < n; i++) {
            if (s1[i] == '1' && s2[i] == '1') {
                // When both rows have a trap, it's possible to move between them.
                currentRow = 1 - currentRow; // Switch rows
            } else if (s1[i] == '0' && currentRow == 1) {
                // If current row is bottom row (1) and it's safe, stay there.
                continue;
            } else if (s2[i] == '0' && currentRow == 0) {
                // If current row is top row (0) and it's safe, stay there.
                continue;
            } else {
                // If neither condition allows a move forward, it’s a dead end
                return "NO";
            }
        }
        
        return currentRow == 1 ? "YES" : "NO";
    }
};


#endif