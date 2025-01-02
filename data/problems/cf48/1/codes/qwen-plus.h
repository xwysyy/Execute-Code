#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, int &m, vector<int> &a, vector<array<int, 3>> &ops) {
        vector<int> result;
        int current_max = *max_element(a.begin(), a.end());
        
        for (const auto& op : ops) {
            int type = op[0], l = op[1], r = op[2];
            
            if (type == 1) {
                // Increment elements in the range [l, r]
                for (auto& num : a) {
                    if (l <= num && num <= r) {
                        num += 1;
                        current_max = max(current_max, num);
                    }
                }
            } else if (type == 2) {
                // Decrement elements in the range [l, r]
                bool max_in_range = false;
                for (auto& num : a) {
                    if (l <= num && num <= r) {
                        num -= 1;
                        if (num == current_max - 1)
                            max_in_range = true;
                    }
                }
                if (max_in_range) {
                    current_max = *max_element(a.begin(), a.end());
                }
            }
            result.push_back(current_max);
        }
        
        return result;
    }
};


#endif