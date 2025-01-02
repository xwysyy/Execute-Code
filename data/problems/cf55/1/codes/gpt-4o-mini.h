#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        vector<bool> visited(n + 1, false); // To track visited indices
        int swaps = 0; // To count the total swaps needed

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                int cycle_length = 0; // Length of the current cycle
                int current = i;

                // Traverse the cycle
                while (!visited[current]) {
                    visited[current] = true;
                    current = p[current - 1]; // Move to the next index in the permutation
                    cycle_length++;
                }

                // If cycle_length is greater than 1, we need (cycle_length - 1) swaps
                if (cycle_length > 1) {
                    swaps += (cycle_length - 1);
                }
            }
        }

        return swaps;
    }
};


#endif