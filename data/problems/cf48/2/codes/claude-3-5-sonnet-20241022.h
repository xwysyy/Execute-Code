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
            
            // Update array elements based on operation type
            for (int i = 0; i < n; i++) {
                if (a[i] >= l && a[i] <= r) {
                    // Type 1: increment elements in range
                    if (type == 1) {
                        a[i]++;
                    }
                    // Type 2: decrement elements in range
                    else {
                        a[i]--;
                    }
                }
            }
            
            // Find maximum value after current operation
            int max_val = a[0];
            for (int i = 1; i < n; i++) {
                max_val = max(max_val, a[i]);
            }
            result.push_back(max_val);
        }
        
        return result;
    }
};


#endif