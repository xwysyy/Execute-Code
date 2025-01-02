#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Count the number of factors of 2 in the product of the array.
        int totalFactorsOf2 = 0;
        for (int i = 0; i < n; ++i) {
            int num = a[i];
            while (num % 2 == 0) {
                totalFactorsOf2++;
                num /= 2;
            }
        }

        // Calculate how many more factors of 2 are needed.
        int neededFactorsOf2 = n - totalFactorsOf2;

        // If the product already has enough factors of 2, no operations are needed.
        if (neededFactorsOf2 <= 0) return 0;

        // Count the number of indices that can provide at least one factor of 2.
        int availableIndices = 0;
        for (int i = 1; i <= n; ++i) {
            int index = i;
            while (index % 2 == 0) {
                availableIndices++;
                index /= 2;
            }
        }

        // If there are not enough indices to provide the needed factors of 2, return -1.
        if (availableIndices < neededFactorsOf2) return -1;

        // Otherwise, return the number of operations required.
        return neededFactorsOf2;
    }
};


#endif