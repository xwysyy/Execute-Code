#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long inversions = 0, zeroToOne = 0, oneToZero = 0;
        int ones = 0, zeros = 0;

        // Count the number of ones and zeros in the array
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) ones++;
            else zeros++;
        }

        // Calculate initial number of inversions
        int countOnesSoFar = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                inversions += countOnesSoFar;
            }
            if (a[i] == 1) {
                countOnesSoFar++;
            }
        }

        // Calculate the maximum possible inversions after flipping one element
        countOnesSoFar = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                zeroToOne = max(zeroToOne, countOnesSoFar + (ones - countOnesSoFar));
            } else {
                oneToZero = max(oneToZero, countOnesSoFar - 1 + (zeros - (i - countOnesSoFar + 1)));
                countOnesSoFar++;
            }
        }

        // Return the maximum of initial inversions and the best possible inversions after one flip
        return max(inversions, max(inversions + zeroToOne - countOnesSoFar, inversions + oneToZero + (n - countOnesSoFar)));
    }
};


#endif