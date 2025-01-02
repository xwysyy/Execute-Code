#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {   
        int minRemovals = n;
        
        // Function to find the minimum removals if we remove 'pie' or 'map' starting from index i
        auto check = [&](int start, const string &pattern) {
            int removals = 0, j = 0;
            for (int i = start; i < n; ++i) {
                if (s[i] == pattern[j]) {
                    j++;
                    if (j == pattern.size()) {
                        removals = i - start + 1 - pattern.size();
                        break;
                    }
                }
            }
            return removals;
        };
        
        // Check all possible starting points for 'pie' and 'map'
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'p') {
                int removals = check(i, "pie");
                minRemovals = min(minRemovals, removals);
            }
            if (s[i] == 'm') {
                int removals = check(i, "map");
                minRemovals = min(minRemovals, removals);
            }
        }
        
        // If no 'pie' or 'map' found, no removals needed
        if (minRemovals == n) {
            return 0;
        }
        
        return minRemovals;
    }
};

#endif