#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        // Calculate the original number of inversions
        long long original_inversions = 0;
        int count_ones = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                count_ones++;
            } else {
                original_inversions += count_ones;
            }
        }

        // Calculate the maximum possible inversions after flipping each element
        long long max_inversions = original_inversions;
        for (int i = 0; i < n; ++i) {
            // Flip the current element
            if (a[i] == 0) {
                // If flipping 0 to 1, we need to calculate the new inversions
                // The number of inversions increases by the number of 1s before it
                // and decreases by the number of 0s after it
                long long new_inversions = original_inversions + count_ones - (i - (count_ones - (a[i] == 1)));
                max_inversions = max(max_inversions, new_inversions);
            } else {
                // If flipping 1 to 0, we need to calculate the new inversions
                // The number of inversions decreases by the number of 1s before it
                // and increases by the number of 0s after it
                long long new_inversions = original_inversions - (count_ones - 1) + (n - i - 1 - (count_ones - 1));
                max_inversions = max(max_inversions, new_inversions);
            }
        }

        return max_inversions;
    }
};


#endif