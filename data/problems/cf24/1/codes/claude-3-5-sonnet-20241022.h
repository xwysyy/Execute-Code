#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // For n=1, only one color possible with cost 0
        if (n == 1) return 0;
        
        // For n=2, only one color possible with max-min difference
        if (n == 2) return abs(a[0] - a[1]);
        
        // Sort the array to make it easier to find max differences
        vector<int> sorted = a;
        sort(sorted.begin(), sorted.end());
        
        // The maximum cost will be the sum of differences between
        // consecutive pairs of numbers in sorted order
        int maxCost = 0;
        for (int i = 1; i < n; i++) {
            maxCost += sorted[i] - sorted[i-1];
        }
        
        return maxCost;
    }
};


#endif