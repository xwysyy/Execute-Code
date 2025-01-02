#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {   
        long long inversions = 0;
        int zerosBefore = 0, onesAfter = 0, totalOnes = 0;

        // Calculate initial number of inversions and count the number of ones
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                inversions += zerosBefore;
                totalOnes++;
            } else {
                zerosBefore++;
            }
        }

        // If all elements are 1s or 0s, no operation can increase inversions
        if (totalOnes == 0 || totalOnes == n) {
            return inversions;
        }

        // Calculate the maximum possible inversions after flipping one element
        long long maxInversions = inversions;
        zerosBefore = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                // If we flip this 1 to 0, we lose all inversions it was contributing
                long long newInversions = inversions - zerosBefore;
                // Add the number of 1s that come after this position
                newInversions += totalOnes - (zerosBefore + 1);
                maxInversions = max(maxInversions, newInversions);
                zerosBefore++;
            }
        }

        // Check if flipping a 0 to 1 can increase the number of inversions
        zerosBefore = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                // If we flip this 0 to 1, we gain inversions from all 1s that come after this position
                long long newInversions = inversions + (totalOnes - zerosBefore);
                maxInversions = max(maxInversions, newInversions);
            } else {
                zerosBefore++;
            }
        }

        return maxInversions;
    }
};

#endif