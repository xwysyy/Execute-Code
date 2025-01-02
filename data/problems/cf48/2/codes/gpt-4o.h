#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<int> solve(int &n, int &m, std::vector<int> &a, std::vector<std::array<int, 3>> &ops) {
        // Result vector to store the maximum after each operation
        std::vector<int> result;

        // Iterate over each operation
        for (const auto& op : ops) {
            int type = op[0];
            int l = op[1];
            int r = op[2];
            
            // Traverse through the array `a`
            for (int i = 0; i < n; ++i) {
                if (a[i] >= l && a[i] <= r) {
                    if (type == 1) {
                        a[i] += 1;
                    } else if (type == 2) {
                        a[i] -= 1;
                    }
                }
            }
        
            // Compute the maximum element in the array after this operation
            int maxVal = *std::max_element(a.begin(), a.end());
            result.push_back(maxVal);
        }
        
        return result;
    }
};


#endif