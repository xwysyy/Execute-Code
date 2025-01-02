#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        if (n == 0) return 0;

        std::vector<int> dp;
        
        for (int i = 0; i < n; i++) {
            // Use binary search to find the position to replace or extend
            auto it = std::lower_bound(dp.begin(), dp.end(), a[i], std::greater<int>());
            if (it == dp.end()) {
                dp.push_back(a[i]); // Append if it's smaller than all in dp
            } else {
                *it = a[i]; // Replace the found position
            }
        }
        
        // Length of longest non-increasing subsequence
        int LNIS_length = dp.size();
        
        // Number of elements to remove to make it vulnerable
        return n - LNIS_length;
    }
};


#endif