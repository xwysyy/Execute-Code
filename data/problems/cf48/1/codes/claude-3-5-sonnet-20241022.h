#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, int &m, vector<int> &a, vector<array<int, 3>> &ops) {
        vector<int> result;
        
        // Process each operation
        for (const auto &op : ops) {
            int type = op[0];
            int l = op[1];
            int r = op[2];
            
            // Update array based on operation type
            for (int i = 0; i < n; i++) {
                // Check if current element is in range [l, r]
                if (a[i] >= l && a[i] <= r) {
                    // Type 1: increment
                    if (type == 1) {
                        a[i]++;
                    }
                    // Type 2: decrement
                    else {
                        a[i]--;
                    }
                }
            }
            
            // Find maximum value after current operation
            int maxVal = a[0];
            for (int i = 1; i < n; i++) {
                maxVal = max(maxVal, a[i]);
            }
            result.push_back(maxVal);
        }
        
        return result;
    }
};


#endif