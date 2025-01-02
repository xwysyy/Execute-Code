#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long sum = 0;
        int negCount = 0;
        long long minAbsValue = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            sum += abs(a[i]);
            if (a[i] < 0) {
                negCount++;
            }
            minAbsValue = min(minAbsValue, static_cast<long long>(abs(a[i])));
        }

        // If the number of negative numbers is odd, we can't make all elements positive.
        // We need to subtract twice the smallest absolute value element from the sum.
        if (negCount % 2 != 0) {
            sum -= 2 * minAbsValue;
        }

        return sum;
    }
};


#endif