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
            
            for (auto& value : a) {
                if (value >= l && value <= r) {
                    if (type == 1) {
                        value += 1;
                    } else if (type == 2) {
                        value -= 1;
                    }
                }
            }
            current_max = *max_element(a.begin(), a.end());
            result.push_back(current_max);
        }
        
        return result;
    }
};


#endif