#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {
        vector<long long> result(n);
        int totalZeros = 0;

        // Count total zeros in the string
        for (char ch : s) {
            if (ch == '0') {
                totalZeros++;
            }
        }

        // Iterating for each i
        for (int i = 1; i <= n; i++) {
            if (totalZeros < i) {
                // Not enough zeros to make divisible by 2^i
                result[i - 1] = -1;
            } else {
                // We need at least `i` zeros at the end
                int neededZeros = i;
                long long swaps = 0;
                int countZerosAtEnd = 0;

                // Calculate swaps needed
                for (int j = n - 1; j >= 0 && neededZeros > 0; j--) {
                    if (s[j] == '0') {
                        countZerosAtEnd++;
                        neededZeros--;
                    } else {
                        // For every '1' before we found enough zeros, we would need 1 swap for each '0' we need to move to the end
                        swaps += countZerosAtEnd;
                    }
                }

                result[i - 1] = swaps;
            }
        }

        return result;
    }
};


#endif