#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // The maximum possible value is the maximum element in the array
        // because we can always choose the entire array and set all elements to its median
        // which is the maximum element itself.
        int max_val = *max_element(a.begin(), a.end());
        return max_val;
    }
};


#endif