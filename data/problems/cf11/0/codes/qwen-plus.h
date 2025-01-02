#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int operations = 0;
        int requiredPowers = n;
        vector<int> powers(n, 0);

        // Count the number of factors of 2 in each element
        for (int i = 0; i < n; ++i) {
            int num = a[i];
            while (num % 2 == 0) {
                num /= 2;
                powers[i]++;
            }
        }

        // Sum up the total number of factors of 2 currently in the product
        int currentPowers = 0;
        for (int power : powers) {
            currentPowers += power;
        }

        // If already divisible by 2^n, return 0
        if (currentPowers >= requiredPowers) {
            return 0;
        }

        // Sort indices based on how many additional factors of 2 they can contribute
        vector<pair<int, int>> indexPowerPairs;
        for (int i = 0; i < n; ++i) {
            int additionalPowers = __builtin_ctz(i + 1); // Count trailing zeros in binary representation
            indexPowerPairs.push_back({additionalPowers, i});
        }
        sort(indexPowerPairs.rbegin(), indexPowerPairs.rend());

        // Apply operations to achieve the required number of factors of 2
        for (auto &pair : indexPowerPairs) {
            int additionalPowers = pair.first;
            if (currentPowers + additionalPowers >= requiredPowers) {
                return operations + 1;
            }
            currentPowers += additionalPowers;
            operations++;
        }

        // If we cannot achieve the required number of factors of 2
        if (currentPowers < requiredPowers) {
            return -1;
        }

        return operations;
    }
};


#endif