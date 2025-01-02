#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int max_length = 0;     // To track the maximum length of blanks (0s)
        int current_length = 0; // To count the current streak of blanks (0s)
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                // If the current element is 0, increment the current blank space streak
                current_length++;
            } else {
                // If the current element is 1, compare and reset the current_length
                if (current_length > max_length) {
                    max_length = current_length;
                }
                current_length = 0; // Restart counting for a new potential blank space
            }
        }
        
        // Final check after the loop in case the longest blank space ends at the last element
        if (current_length > max_length) {
            max_length = current_length;
        }
        
        return max_length; // Return the longest length found
    }
};


#endif