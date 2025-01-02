#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long sum = 0;
        int neg_count = 0;
        long long min_abs = 1e9 + 7;

        for (int x : a) {
            sum += abs(x);
            if (x < 0) {
                neg_count++;
            }
            min_abs = min(min_abs, (long long)abs(x));
        }

        if (neg_count % 2 == 0) {
            return sum;
        } else {
            return sum - 2 * min_abs;
        }
    }
};


#endif