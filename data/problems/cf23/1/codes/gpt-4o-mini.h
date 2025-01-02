#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int maxBlankSpace = 0;
        int currentBlankSpace = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                currentBlankSpace++;  // Increment counter of current 0's
            } else {
                maxBlankSpace = max(maxBlankSpace, currentBlankSpace);  // Update max if current is greater
                currentBlankSpace = 0;  // Reset current counter for next segment
            }
        }
        
        // Final check at the end of the array
        maxBlankSpace = max(maxBlankSpace, currentBlankSpace);
        
        return maxBlankSpace;
    }
};


#endif