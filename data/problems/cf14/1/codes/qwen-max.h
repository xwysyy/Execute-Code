#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {   
        long long sum = 0;
        int min_abs_val = INT_MAX;
        bool has_zero = false;

        for (int i = 0; i < n; ++i) {
            sum += abs(a[i]);
            min_abs_val = min(min_abs_val, abs(a[i]));
            if (a[i] == 0) {
                has_zero = true;
            }
        }

        // If the number of negative elements is odd and there are no zeros,
        // we need to subtract twice the minimum absolute value to account for
        // the last flip that will make one element negative.
        int neg_count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < 0) {
                neg_count++;
            }
        }

        if (neg_count % 2 != 0 && !has_zero) {
            sum -= 2 * min_abs_val;
        }

        return sum;
    }
};

#endif