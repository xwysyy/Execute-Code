#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        // Sort the array
        std::sort(a.begin(), a.end());
        
        // Calculate the maximum median position, which is floor((n+1)/2) - 1
        int max_median_index = (n - 1) / 2;
        
        // Return the median value
        return a[max_median_index];
    }
};


#endif