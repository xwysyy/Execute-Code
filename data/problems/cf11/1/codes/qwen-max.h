#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        int operations = 0;
        int twos_needed = n;
        vector<int> count_twos(n + 1, 0);

        // Count the number of 2's in each element
        for (int i = 0; i < n; ++i) {
            while (a[i] % 2 == 0) {
                a[i] /= 2;
                count_twos[i + 1]++;
            }
        }

        // Calculate the total number of 2's in the product
        for (int i = 1; i <= n; ++i) {
            twos_needed -= count_twos[i];
            if (twos_needed <= 0) {
                return operations;
            }
            if (count_twos[i] == 0) {
                operations++;
                twos_needed--;
            }
        }

        return twos_needed > 0 ? -1 : operations;
    }
};

#endif