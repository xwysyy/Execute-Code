#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long sum = 0;
        int negCount = 0;
        int minAbsValue = INT_MAX;

        for (int i = 0; i < n; ++i) {
            sum += abs(a[i]);  // Calculate the sum of absolute values
            if (a[i] < 0) {
                negCount++;  // Count the number of negative elements
            }
            minAbsValue = min(minAbsValue, abs(a[i]));  // Track the minimum absolute value
        }

        // If the count of negative numbers is odd, we can't make all elements positive.
        // We need to subtract twice the minimum absolute value from the sum.
        if (negCount % 2 != 0) {
            sum -= 2 * minAbsValue;
        }

        return sum;
    }
};


#endif