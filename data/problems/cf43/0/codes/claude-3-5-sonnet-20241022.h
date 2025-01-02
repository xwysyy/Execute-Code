#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int ans = 0;
        // For each possible value in the array
        for (int val : a) {
            // Count how many elements are greater than or equal to val
            int cnt = 0;
            for (int x : a) {
                if (x >= val) cnt++;
            }
            // If we can make more than half of the elements equal to val
            // then val is a possible answer
            if (cnt >= (n + 1) / 2) {
                ans = max(ans, val);
            }
        }
        return ans;
    }
};


#endif