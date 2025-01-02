#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) { 
        // write your code here
        int result = 0;
        bool isConnected = false;
        int freeCells = 0;

        for (int i = 0; i < n; ++i) {
            if (s1[i] == '.' || s2[i] == '.') {
                freeCells++;
                if ((i > 0 && (s1[i-1] == '.' || s2[i-1] == '.')) || (s1[i] == '.' && s2[i] == '.')) {
                    isConnected = true;
                }
            } else {
                if (isConnected) {
                    int blockedCellsMakeThreeRegions = 0;
                    if (i > 0 && (s1[i-1] == '.' || s2[i-1] == '.')) {
                        blockedCellsMakeThreeRegions++;
                    }
                    if (i < n - 1 && (s1[i+1] == '.' || s2[i+1] == '.')) {
                        blockedCellsMakeThreeRegions++;
                    }
                    if (s1[i] == 'x' && s2[i] == 'x' && (s1[i-1] == '.' || s2[i-1] == '.') && (s1[i+1] == '.' || s2[i+1] == '.')) {
                        blockedCellsMakeThreeRegions++;
                    }
                    result += blockedCellsMakeThreeRegions;
                }
                isConnected = false;
            }
        }

        // Check the last segment
        if (isConnected) {
            if (s1[n-1] == 'x' && s2[n-1] == 'x' && (s1[n-2] == '.' || s2[n-2] == '.')) {
                result++;
            }
        }

        return result;
    }
};


#endif