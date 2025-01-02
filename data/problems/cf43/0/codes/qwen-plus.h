#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Sort the array to easily find medians
        sort(a.begin(), a.end());
        
        // The maximum possible value after performing operations will be the median of the entire array
        // If n is odd, the median is the middle element
        // If n is even, the median can be either of the two middle elements, we choose the larger one
        if (n % 2 == 1) {
            return a[n / 2];
        } else {
            return a[n / 2]; // For even, choosing the second middle element as it's the upper median
        }
    }
};


#endif