#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {
        // Keep track of numbers we have
        vector<bool> have(n + 1, false);
        int maxValid = 0;
        
        // Count how many numbers are valid for permutation
        for (int x : a) {
            if (x <= n) {
                have[x] = true;
                maxValid = max(maxValid, x);
            }
        }
        
        long long result = LLONG_MAX;
        
        // Try all possible permutation lengths from 1 to max(n, maxValid)
        for (int len = 1; len <= max(n, maxValid); len++) {
            long long cost = 0;
            
            // Count numbers we need to remove
            // 1. Numbers greater than len
            // 2. Duplicate numbers <= len
            vector<bool> used = have;
            for (int x : a) {
                if (x > len || (x <= len && !used[x])) {
                    cost += c;
                } else if (x <= len) {
                    used[x] = false;
                }
            }
            
            // Count numbers we need to insert to complete the permutation
            for (int i = 1; i <= len; i++) {
                if (have[i] == false) {
                    cost += d;
                }
            }
            
            result = min(result, cost);
        }
        
        return result;
    }
};


#endif