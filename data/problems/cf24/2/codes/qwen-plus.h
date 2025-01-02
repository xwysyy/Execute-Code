#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Sort the array
        sort(a.begin(), a.end());
        
        int max_cost = 0;
        
        // Iterate from both ends towards the center
        for (int i = 0; i < n / 2; ++i) {
            max_cost += a[n - 1 - i] - a[i];
        }
        
        return max_cost;
    }
};


#endif