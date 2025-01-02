#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long inversions = 0;
        int zerosBefore = 0, onesAfter = 0;
        
        // Calculate initial number of inversions and count of zeros before and ones after
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                inversions += zerosBefore;
                onesAfter++;
            } else {
                zerosBefore++;
            }
        }
        
        // The maximum possible inversions by flipping a 0 to 1
        long long maxInversionsByFlippingZero = inversions + onesAfter - 1;
        
        // The maximum possible inversions by flipping a 1 to 0
        long long maxInversionsByFlippingOne = inversions + zerosBefore - 1;
        
        // Return the maximum of the two possibilities
        return max(inversions, max(maxInversionsByFlippingZero, maxInversionsByFlippingOne));
    }
};

#endif