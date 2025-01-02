#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long initialInversions = 0;
        long long totalOnesBefore = 0;

        // Calculate the initial number of inversions
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                initialInversions += (n - i - 1); // Count how many 0s are after this 1
            } else {
                initialInversions += totalOnesBefore; // Count how many 1s are before this 0
                totalOnesBefore++;
            }
        }

        long long maxInversions = initialInversions;

        // Check the impact of flipping each bit
        totalOnesBefore = 0; // Reset to calculate influence of flipping

        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                // If we flip this 0 to 1, we gain totalOnesBefore additional pairs
                // and lose (n - i - 1) pairs (since total 1s after this index)
                long long newInversions = initialInversions + totalOnesBefore - (n - i - 1);
                maxInversions = max(maxInversions, newInversions);
            } else {
                // If we flip this 1 to 0, we gain (n - i - 1) pairs (before the current 1)
                // and lose totalOnesBefore pairs (1s before this index)
                long long newInversions = initialInversions + (n - i - 1) - totalOnesBefore;
                maxInversions = max(maxInversions, newInversions);
            }
            if (a[i] == 1) {
                totalOnesBefore++; // Update the count of 1s before the current position
            }
        }

        return maxInversions;
    }
};


#endif