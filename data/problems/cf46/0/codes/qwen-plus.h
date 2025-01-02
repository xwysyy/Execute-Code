#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) { 
        int result = 0;
        bool hasRegion = false;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '.' || s2[i] == '.') {
                // Check if blocking this cell will split the region into exactly 3 regions
                bool canSplitIntoThree = false;
                if (s1[i] == '.' && (i == 0 || s1[i-1] == 'x') && (i == n-1 || s1[i+1] == 'x') && (s2[i] == 'x' || (i == 0 || s2[i-1] == 'x') && (i == n-1 || s2[i+1] == 'x'))) {
                    canSplitIntoThree = true;
                }
                if (s2[i] == '.' && (i == 0 || s2[i-1] == 'x') && (i == n-1 || s2[i+1] == 'x') && (s1[i] == 'x' || (i == 0 || s1[i-1] == 'x') && (i == n-1 || s1[i+1] == 'x'))) {
                    canSplitIntoThree = true;
                }

                if (canSplitIntoThree) {
                    result++;
                } else {
                    hasRegion = true;
                }
            }
        }

        // If there is no connected region initially, return 0
        if (!hasRegion) {
            return 0;
        }

        return result;
    }
};


#endif