#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {
        int totalSaved = 0;   // Total magazines that can be saved
        int availableLids = 0; // Count of lids available to save magazines

        // Traverse through each box
        for (int i = 0; i < n; i++) {
            // If the current box has a lid
            if (s[i] == '1') {
                availableLids++; // Count the lid
                totalSaved += a[i]; // Save its magazines
            } 
            // If the current box does not have a lid
            else {
                // If there's a lid available to move
                if (availableLids > 0) {
                    availableLids--; // Use a lid to save the magazines in this box
                    totalSaved += a[i]; // Save its magazines
                }
            }
        }
        
        return totalSaved; // Return the total saved magazines
    }
};


#endif