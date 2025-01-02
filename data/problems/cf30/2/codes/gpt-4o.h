#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {
        vector<long long> results(n, -1);  // Initialize results with -1 (impossible)

        for (int i = 1; i <= n; ++i) {
            int target_zeros = i;
            int zero_count = 0;
            int swaps = 0;
            
            // Step 1: Count if we have at least `target_zeros`
            for (int j = n - 1; j >= 0 && zero_count < target_zeros; --j) {
                if (s[j] == '0') {
                    ++zero_count;
                }
            }
            
            // If not enough zeros, the result remains -1
            if (zero_count < target_zeros) {
                continue;
            }
            
            // Step 2: Calculate the minimum swaps to move zeroes to the end
            zero_count = 0;
            int current_position = n - 1;
            int needed_zero_position = n - 1;
            
            while (zero_count < target_zeros) {
                if (s[current_position] == '0') {
                    swaps += needed_zero_position - current_position;
                    needed_zero_position--;
                    zero_count++;
                }
                current_position--;
            }
            
            results[i - 1] = swaps;
        }
        
        return results;
    }
};


#endif