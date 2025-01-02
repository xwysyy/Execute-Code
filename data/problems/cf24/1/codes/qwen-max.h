#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a) {
        if (n == 1) return 0; // If there's only one element, the cost is 0.
        
        // Sort the array to easily find the min and max values.
        sort(a.begin(), a.end());
        
        // The maximum possible cost is the difference between the largest and smallest elements.
        int max_cost = a[n - 1] - a[0];
        
        return max_cost;
    }
};

#endif