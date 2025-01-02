#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        int operations = 0;
        int twos_needed = n;
        vector<int> two_count(n + 1, 0);

        // Count the number of 2's in each a[i]
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            while (x % 2 == 0) {
                x /= 2;
                two_count[i + 1]++;
            }
        }

        // Calculate the total number of 2's in the product
        for (int i = 1; i <= n; ++i) {
            twos_needed -= min(twos_needed, two_count[i]);
        }

        // If we have enough 2's, return 0
        if (twos_needed == 0) {
            return 0;
        }

        // Try to get more 2's by multiplying with indices
        for (int i = 1; i <= n && twos_needed > 0; ++i) {
            int x = i;
            while (x % 2 == 0 && twos_needed > 0) {
                x /= 2;
                twos_needed--;
                operations++;
            }
        }

        // If we still need more 2's, it's not possible
        if (twos_needed > 0) {
            return -1;
        }

        return operations;
    }
};

#endif