#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long max_inversions = 0;
        long long current_inversions = 0;
        long long zero_count = 0;
        long long one_count = 0;

        // Calculate initial number of inversions and count of 0s and 1s
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                zero_count++;
                max_inversions += one_count; // Each 0 can pair with all previous 1s to form inversions
            } else {
                one_count++;
                current_inversions += zero_count; // Each 1 can pair with all previous 0s to form inversions
            }
        }

        // Try flipping each bit to see the effect on the number of inversions
        long long best_flip_improvement = 0;
        zero_count = 0;
        one_count = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                // If we flip this 0 to 1, it will create new inversions with all previous 1s
                best_flip_improvement = max(best_flip_improvement, one_count - zero_count);
                zero_count++;
            } else {
                // If we flip this 1 to 0, it will reduce existing inversions with all previous 0s
                best_flip_improvement = max(best_flip_improvement, zero_count - one_count);
                one_count++;
            }
        }

        return max_inversions + best_flip_improvement;
    }
};


#endif