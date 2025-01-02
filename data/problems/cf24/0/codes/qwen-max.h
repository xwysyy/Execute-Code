#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a) {
        // To maximize the cost, we can paint all elements with a single color.
        // The cost of this coloring will be the difference between the maximum and minimum values in the array.
        int min_val = *min_element(a.begin(), a.end());
        int max_val = *max_element(a.begin(), a.end());
        return max_val - min_val;
    }
};

#endif