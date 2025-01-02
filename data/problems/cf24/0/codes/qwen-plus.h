#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 1) return 0; // If there's only one element, the cost is 0 as max-min for a single element is 0.
        
        // Sort the array to find the maximum difference between consecutive elements.
        sort(a.begin(), a.end());
        
        // The maximum possible cost is achieved by painting each element in such a way that maximizes the differences.
        // This can be done by splitting the array into two colors: one color for the smallest and largest elements,
        // and another color for the rest. The maximum cost will be the difference between the largest and smallest elements.
        return a[n-1] - a[0];
    }
};


#endif