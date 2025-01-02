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
                } else {
                    removals++;
                }
            }
            return removals;
        };
        
        // Iterate over all possible starting positions for 'pie' and 'map'
        for (int i = 0; i < n; ++i) {
            if (i + 2 < n && s.substr(i, 3) == "pie") {
                minRemovals = min(minRemovals, check(i, "pie"));
            }
            if (i + 2 < n && s.substr(i, 3) == "map") {
                minRemovals = min(minRemovals, check(i, "map"));
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