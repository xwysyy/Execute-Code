#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long original_inversions = 0;
        long long count_ones = 0;

        // Calculate the original number of inversions
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                count_ones++;
            } else {
                original_inversions += count_ones;
            }
        }

        long long max_inversions = original_inversions;
        long long current_inversions = original_inversions;
        long long ones_before = 0;
        long long zeros_after = 0;

        // Precompute the number of zeros after each index
        vector<long long> zeros_after_index(n, 0);
        long long zeros_count = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == 0) {
                zeros_count++;
            }
            zeros_after_index[i] = zeros_count;
        }

        // Iterate through the array to find the best flip
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                // If we flip 1 to 0, we lose the inversions caused by this 1
                // and gain the inversions caused by the zeros after it
                long long new_inversions = current_inversions - zeros_after_index[i] + ones_before;
                max_inversions = max(max_inversions, new_inversions);
                ones_before++;
            } else {
                // If we flip 0 to 1, we gain the inversions caused by this 1
                // and lose the inversions caused by the ones before it
                long long new_inversions = current_inversions + ones_before - zeros_after_index[i];
                max_inversions = max(max_inversions, new_inversions);
            }
        }

        return max_inversions;
    }
};


#endif