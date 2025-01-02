#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<int> solve(int &n, int &m, std::vector<int> &a, std::vector<std::array<int, 3>> &ops) {
        std::vector<int> results;
        
        // Iterate through each operation
        for (const auto &op : ops) {
            int op_type = op[0];
            int l = op[1];
            int r = op[2];
            
            // Apply the operation to array `a`
            for (int i = 0; i < n; i++) {
                // If a[i] is within the given range [l, r], update it
                if (a[i] >= l && a[i] <= r) {
                    if (op_type == 1) {
                        a[i] += 1;
                    } else if (op_type == 2) {
                        a[i] -= 1;
                    }
                }
            }
            
            // Find the maximum value in the array after the operation
            int max_val = *std::max_element(a.begin(), a.end());
            results.push_back(max_val);
        }
        
        return results;
    }
};


#endif