#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 1) return 0; // Edge case: only one element

        // Sort the array
        sort(a.begin(), a.end());

        int maxCost = 0;

        // Pair the smallest and largest elements to maximize the cost
        for (int i = 0; i < n / 2; ++i) {
            maxCost += a[n - 1 - i] - a[i];
        }

        // If there's an odd number of elements, the middle element won't be paired
        // but it doesn't contribute to the cost since it would be painted alone with cost 0

        return maxCost;
    }
};


#endif