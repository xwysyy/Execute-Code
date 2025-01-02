#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long inversions = 0;
        int zeros = 0, ones = 0;
        
        // Calculate initial number of inversions and count of 0s and 1s
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                inversions += ones; // Each 0 after a 1 is an inversion
                zeros++;
            } else {
                ones++;
            }
        }
        
        // Calculate the maximum possible inversions by flipping one 0 to 1 or one 1 to 0
        long long maxInversions = inversions;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                // If we flip this 0 to 1, it will add (ones - (number of 1s before this 0)) inversions
                maxInversions = max(maxInversions, inversions + ones - (ones - zeros + 1));
            } else {
                // If we flip this 1 to 0, it will remove (zeros - (number of 0s before this 1)) inversions
                maxInversions = max(maxInversions, inversions - (zeros - (ones - 1)));
            }
        }
        
        return maxInversions;
    }
};

#endif