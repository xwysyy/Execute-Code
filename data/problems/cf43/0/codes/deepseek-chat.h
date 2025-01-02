#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // The maximum possible value is the maximum value in the array
        // because we can always choose a subarray that includes the maximum value
        // and set all elements in that subarray to the maximum value.
        // Then, we can continue to expand this subarray until the entire array
        // is filled with the maximum value.
        int max_val = *max_element(a.begin(), a.end());
        return max_val;
    }
};


#endif