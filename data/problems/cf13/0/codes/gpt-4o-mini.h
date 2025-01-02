#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long current_inversions = 0;

        // Count current inversions
        int count_ones_after = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == 1) {
                current_inversions += count_ones_after; // Count inversions with a[i] = 1
            } else {
                count_ones_after++; // Count how many 1s are after some 0s
            }
        }

        long long max_inversions = current_inversions;

        // Evaluate the effect of flipping each bit
        count_ones_after = 0;
        int count_zeros_before = 0;
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                // Flipping 1 to 0
                long long inversions_if_flipped = current_inversions - (count_zeros_before - count_ones_after);
                max_inversions = max(max_inversions, inversions_if_flipped);
                count_ones_after++;
            } else {
                // Flipping 0 to 1
                long long inversions_if_flipped = current_inversions + count_ones_after;
                max_inversions = max(max_inversions, inversions_if_flipped);
                count_zeros_before++;
            }
        }

        return max_inversions;
    }
};


#endif