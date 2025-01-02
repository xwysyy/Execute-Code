#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        if (n == 0) return 0;
        
        vector<int> lis;
        for (int num : a) {
            auto it = lower_bound(lis.begin(), lis.end(), num, greater<int>());
            if (it == lis.end()) {
                lis.push_back(num);
            } else {
                *it = num;
            }
        }
        
        return n - lis.size();
    }
};


#endif