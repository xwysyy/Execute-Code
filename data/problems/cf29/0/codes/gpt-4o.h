#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {
        int maxLength = 0;
        int l = 0;
        int current_fruits = 0;
        
        for (int r = 0; r < n; ++r) {
            current_fruits += a[r];
            
            // While current fruits exceed k or the divisibility condition is violated, move the left pointer
            while (current_fruits > k || (l < r && h[l] % h[l + 1] != 0)) {
                current_fruits -= a[l];
                ++l;
            }
            
            // Update max length of the valid subarray
            maxLength = max(maxLength, r - l + 1);
        }
        
        return maxLength;
    }
};


#endif