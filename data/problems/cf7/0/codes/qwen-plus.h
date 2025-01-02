#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {   
        int savedMagazines = 0;
        bool hasLidAvailable = false;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                // If the current box has a lid, save the magazines in this box
                savedMagazines += a[i];
                // Check if we can use this lid for the previous box
                if (hasLidAvailable) {
                    // We had an extra lid available from the previous iteration
                    savedMagazines += a[i - 1];
                    hasLidAvailable = false;
                }
            } else {
                // If the current box does not have a lid, check if the next box can use this lid
                if (i + 1 < n && s[i + 1] == '0') {
                    hasLidAvailable = true;
                } else if (hasLidAvailable) {
                    // We had an extra lid available and the current box doesn't have a lid
                    savedMagazines += a[i];
                    hasLidAvailable = false;
                }
            }
        }
        
        // Check if there is an extra lid that can be used for the last box
        if (hasLidAvailable && n > 0) {
            savedMagazines += a[n - 1];
        }
        
        return savedMagazines;
    }
};


#endif