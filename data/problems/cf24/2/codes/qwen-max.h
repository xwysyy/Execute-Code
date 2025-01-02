#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        // To maximize the cost, we should try to maximize the difference between max and min for each color.
        // The maximum possible cost is achieved by painting all elements with the same color.
        // In that case, the cost will be the difference between the maximum and minimum values in the array.
        int max_val = *max_element(a.begin(), a.end());
        int min_val = *min_element(a.begin(), a.end());
        return max_val - min_val;
    }
};

#endif