#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long total_sum = 0;
        long long min_negate_sum = 0;
        long long negate_sum = 0;

        for (int i = 0; i < n; ++i) {
            total_sum += abs(a[i]);
            if (i > 0) {
                // Calculate contribution to negate_sum for negative adjacent pairs
                long long pair_sum = a[i-1] + a[i];
                negate_sum += abs(pair_sum) - (abs(a[i-1]) + abs(a[i]));
                
                // We seek the pairing with opposite sign if possible
                min_negate_sum = std::min(min_negate_sum, negate_sum);
            }
        }

        return total_sum + min_negate_sum;
    }
};


#endif