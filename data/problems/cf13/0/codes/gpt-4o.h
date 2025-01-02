#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        // Count initial inversions
        long long initialInversions = 0;
        long long onesCount = 0;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                onesCount++;
            } else if (a[i] == 0) {
                initialInversions += onesCount;
            }
        }
        
        // Calculate the maximum possible inversions using one flip
        long long maxInversions = initialInversions;
        long long currentOnesBefore = 0, currentZerosAfter = 0;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                // Flip 0 to 1
                long long potentialInversions = initialInversions + currentOnesBefore;
                maxInversions = std::max(maxInversions, potentialInversions);
                currentZerosAfter++;
            } else if (a[i] == 1) {
                // Flip 1 to 0
                long long potentialInversions = initialInversions - currentZerosAfter;
                maxInversions = std::max(maxInversions, potentialInversions);
                currentOnesBefore++;
            }
        }
        
        return maxInversions;
    }
};


#endif