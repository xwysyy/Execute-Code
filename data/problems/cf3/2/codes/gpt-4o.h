#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Current Row Index: 0 for s1, 1 for s2.
        int currentRow = 0;
        
        for (int col = 0; col < n; ++col) {
            if (currentRow == 0) { // We're on row 1 (`s1`)
                if (s1[col] == '1') {
                    // If we're at '1', we can only move to the current column of the second row
                    if (s2[col] == '0') {
                        // Move to s2
                        currentRow = 1;
                    } else {
                        // Can't move further
                        return "NO";
                    }
                }
            } else { // currentRow == 1, We're on row 2 (`s2`)
                if (s2[col] == '1') {
                    // If we're at '1', we can only move to the current column of the first row
                    if (s1[col] == '0') {
                        // Move to s1
                        currentRow = 0;
                    } else {
                        // Can't move further
                        return "NO";
                    }
                }
            }
        }
        
        // After exiting the loop, we should be in the second row at column n-1
        if (currentRow == 1) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif