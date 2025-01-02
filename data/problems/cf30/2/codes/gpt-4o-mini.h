#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {   
        vector<long long> results(n);
        int zeroCount = 0;

        // Count total zeros
        for (char bit : s) {
            if (bit == '0') {
                zeroCount++;
            }
        }

        // Iterate for each power i from 1 to n
        for (int i = 1; i <= n; i++) {
            if (zeroCount < i) {
                results[i - 1] = -1; // Not enough zeros
                continue;
            }

            long long swaps = 0;
            int onesBetween = 0; // To count ones between zeros

            // We'll only need to calculate where to place the first i zeros
            for (int j = 0; j < n; j++) {
                if (s[j] == '0') {
                    // Count how many ones are before the current zero
                    swaps += onesBetween; // All these ones need to be moved to the left
                    i--; // Reduce the count of zeros we need to place
                    if (i == 0) break; // Placed all required zeros
                } else {
                    onesBetween++; // Counting `1`s between `0`s
                }
            }

            results[i - 1] = swaps; // Store result for i
        }

        return results;
    }
};


#endif