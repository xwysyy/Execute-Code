#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {   
        int savedMagazines = 0;
        bool hasLidToMove = false;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                // If the current box has a lid, save its magazines
                savedMagazines += a[i];
                // Check if we have a lid to move from the next box
                if (i + 1 < n && s[i + 1] == '0') {
                    hasLidToMove = true;
                } else {
                    hasLidToMove = false;
                }
            } else if (hasLidToMove) {
                // If the current box doesn't have a lid but we can move a lid here
                savedMagazines += a[i];
                hasLidToMove = false;
            }
        }
        return savedMagazines;
    }
};


#endif