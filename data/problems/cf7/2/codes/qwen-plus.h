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
                // If the current box has a lid, save its magazines and check if we can move the lid to the previous box.
                savedMagazines += a[i];
                if (hasLidAvailable) {
                    // There was an available lid from a previous iteration, use it here.
                    hasLidAvailable = false;
                } else {
                    // Mark that this lid can potentially be moved to the next box.
                    hasLidAvailable = true;
                }
            } else {
                // If the current box does not have a lid but there is an available lid from a previous box, use it.
                if (hasLidAvailable) {
                    savedMagazines += a[i];
                    hasLidAvailable = false;
                } else {
                    // No lid available, mark that a lid could be moved here from the next box.
                    hasLidAvailable = true;
                }
            }
        }
        
        return savedMagazines;
    }
};


#endif