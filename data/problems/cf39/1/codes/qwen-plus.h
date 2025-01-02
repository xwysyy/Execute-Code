#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {   
        // Check if starting from (1,1) can reach (2,n)
        int row = 0, col = 0;
        bool canReach = false;
        
        // Try starting with the first move to the right
        if (s1[0] == '>') {
            row = 0;
            col = 1;
            while (col < n) {
                if (row == 0) {
                    if (s1[col] == '<') {
                        row = 1;
                    }
                } else {
                    if (s2[col] == '>') {
                        row = 0;
                    }
                }
                col++;
            }
            if (row == 1 && col == n) {
                canReach = true;
            }
        }

        // Reset and try starting with the first move down
        row = 0;
        col = 0;
        if (!canReach && s2[0] == '>') {
            row = 1;
            col = 0;
            while (col < n) {
                if (row == 0) {
                    if (s1[col] == '<') {
                        row = 1;
                    }
                } else {
                    if (s2[col] == '>') {
                        row = 0;
                    }
                }
                col++;
            }
            if (row == 1 && col == n) {
                canReach = true;
            }
        }

        return canReach ? "YES" : "NO";
    }
};


#endif