#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long inversions = 0;
        long long maxInversions = 0;
        int zeroCount = 0;
        int oneCount = 0;

        // Calculate initial number of inversions
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                inversions += oneCount;
                zeroCount++;
            } else {
                oneCount++;
            }
        }

        maxInversions = inversions;

        // Try flipping each bit and calculate the new number of inversions
        zeroCount = 0;
        oneCount = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                // If we flip this 0 to 1, we lose all current inversions caused by this 0
                // But we gain potential new inversions with future 0s
                inversions -= oneCount;
                inversions += (n - i - 1 - zeroCount);
            } else {
                // If we flip this 1 to 0, we gain all current 1s as new inversions
                // But we lose potential new inversions with future 1s
                inversions += (oneCount);
                inversions -= (n - i - 1 - zeroCount);
            }
            maxInversions = max(maxInversions, inversions);

            // Update counts for next iteration
            if (a[i] == 0) zeroCount++;
            else oneCount++;
        }

        return maxInversions;
    }
};


#endif