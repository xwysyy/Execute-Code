#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int ans = 0;
        // For each element, check if it can be the final value
        for (int i = 0; i < n; i++) {
            int val = a[i];
            int left = 0, right = 0;
            
            // Count elements greater and smaller/equal than current value
            for (int j = 0; j < n; j++) {
                if (a[j] > val) right++;
                else left++;
            }
            
            // Check if this value can be the median of some subarray
            // For a value to be possible, we need enough smaller/equal elements
            // to form a valid subarray where this value would be median
            if (left > right) {
                ans = max(ans, val);
            }
        }
        return ans;
    }
};


#endif