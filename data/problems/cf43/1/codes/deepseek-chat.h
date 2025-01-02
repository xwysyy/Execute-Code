#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        // The maximum possible value is the maximum element in the array
        // because we can always choose a subarray that includes the maximum element
        // and set all elements in that subarray to the maximum element.
        // This way, the maximum element will be preserved and eventually
        // the entire array will be set to this maximum value.
        return *std::max_element(a.begin(), a.end());
    }
};


#endif