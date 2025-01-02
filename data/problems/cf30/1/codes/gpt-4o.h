#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<long long> solve(int &n, std::string &s) {
        std::vector<long long> results(n, -1);

        for (int i = 1; i <= n; ++i) {
            int required_zeros = i;
            int zero_count = 0;
            long long swaps_count = 0;
            bool possible = false;

            // Traverse from the end to the beginning
            for (int j = n - 1; j >= 0; --j) {
                if (s[j] == '0') {
                    zero_count++;
                } else {
                    // If when encountering a '1', we expect to have more zeros sooner
                    if (zero_count < required_zeros) {
                        // Calculate how this '1' can be swapped over zeros
                        swaps_count += (required_zeros - zero_count);
                    }
                }
                // Check if we have enough zeros so far
                if (zero_count == required_zeros) {
                    possible = true;
                    results[i - 1] = swaps_count;
                    break;
                }
            }
        }

        return results;
    }
};


#endif