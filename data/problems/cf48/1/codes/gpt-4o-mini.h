#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<int> solve(int &n, int &m, std::vector<int> &a, std::vector<std::array<int, 3>> &ops) {
        // Initialize the delta array
        std::vector<long long> delta(2000001, 0); // Large enough to cover potential ranges

        // Process each operation
        for (const auto& op : ops) {
            int type = op[0];
            int l = op[1];
            int r = op[2];

            if (type == 1) {
                delta[l]++;           // increment start at l
                if (r + 1 < delta.size()) {
                    delta[r + 1]--;   // decrement after r
                }
            } else if (type == 2) {
                delta[l]--;           // decrement start at l
                if (r + 1 < delta.size()) {
                    delta[r + 1]++;   // increment after r
                }
            }
        }

        // Apply the changes and compute maximum
        std::vector<int> result;
        long long current_addition = 0;

        // Note: a[i] can be very large, so we will use a long long for continual additions
        for (int i = 1; i <= 2000000; ++i) {
            current_addition += delta[i];
            if (i < a.size()) {
                a[i] += current_addition; // Update the actual array
                result.push_back(*std::max_element(a.begin(), a.end())); // Get max after each operation
            }
        }

        return result;
    }
};


#endif