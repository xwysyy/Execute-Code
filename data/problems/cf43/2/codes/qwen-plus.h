#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Sort the array to easily find medians
        sort(a.begin(), a.end());
        
        // The maximum possible value of the final array can be found by considering
        // the median of the largest possible subarray. For an odd-length subarray,
        // the median is the middle element. For an even-length subarray, the median
        // is the left-middle element when sorted.
        return a[(n - 1) / 2];
    }
};


#endif