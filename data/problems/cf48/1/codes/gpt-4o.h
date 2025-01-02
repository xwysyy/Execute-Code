#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, int &m, vector<int> &a, vector<array<int, 3>> &ops) {
        // Initialize result vector to store the maximum values after each operation
        vector<int> results;
        
        // Iterate through each operation
        for (const auto& op : ops) {
            int type = op[0];
            int l = op[1];
            int r = op[2];

            // Iterate through the array to apply and record effects of the current operation
            for (int i = 0; i < n; ++i) {
                if (l <= a[i] && a[i] <= r) {
                    // Increment or decrement based on operation type
                    if (type == 1) {
                        a[i] += 1;
                    } else if (type == 2) {
                        a[i] -= 1;
                    }
                }
            }

            // Compute the current maximum value in the array after the operation
            int current_max = *max_element(a.begin(), a.end());
            results.push_back(current_max);
        }
        
        return results;
    }
};


#endif