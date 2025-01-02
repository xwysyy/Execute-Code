#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {   
        // Start at (row 0, col 0)
        int currentRow = 0; 
        int currentCol = 0;
        
        // Iterate through all columns
        while (currentCol < n) {
            if (currentRow == 0) {
                // We are in the first row
                if (s1[currentCol] == '>') {
                    currentCol++;  // Move right
                } else if (s1[currentCol] == '<') {
                    currentRow = 1; // Move down to the second row
                }
            } else {
                // We are in the second row
                if (s2[currentCol] == '>') {
                    currentCol++;  // Move right
                } else if (s2[currentCol] == '<') {
                    currentRow = 0; // Move up to the first row
                }
            }
        
            // At any column check if we reach (2, n) which is (1, n-1)
            if (currentRow == 1 && currentCol == n) {
                return "YES";
            }
        }
        
        // If we finish scanning through columns and never reached (2, n)
        return "NO";
    }
};


#endif