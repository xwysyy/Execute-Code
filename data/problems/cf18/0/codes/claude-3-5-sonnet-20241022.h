#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {
        // Create a set to track unique numbers that could be part of final permutation
        set<int> present;
        long long cost = 0;
        int maxValid = 0;
        
        // First pass: count numbers that could be part of a permutation
        for (int x : a) {
            if (x > 0) {
                present.insert(x);
                maxValid = max(maxValid, x);
            }
        }
        
        // Find the optimal permutation length
        // Try each possible length from 1 to max(maxValid, n)
        long long minCost = LLONG_MAX;
        int optLen = max(maxValid, n);
        
        for (int len = 1; len <= optLen; len++) {
            long long curCost = 0;
            
            // Count numbers to remove (numbers > len or not needed)
            for (int x : a) {
                if (x > len || x <= 0) {
                    curCost += c;
                }
            }
            
            // Count numbers we need to insert to complete permutation
            for (int i = 1; i <= len; i++) {
                if (present.find(i) == present.end() || i > len) {
                    curCost += d;
                }
            }
            
            minCost = min(minCost, curCost);
        }
        
        return minCost;
    }
};


#endif