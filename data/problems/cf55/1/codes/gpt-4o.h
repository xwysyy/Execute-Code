#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        // To store visited elements during cycle detection
        vector<bool> visited(n + 1, false);
        int min_operations = 0; // Minimum swaps needed

        // Explore cycles in the permutation
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) { // Start a new cycle if not visited
                int cycle_length = 0;
                int x = i;

                // Follow the cycle and mark visited nodes
                while (!visited[x]) {
                    visited[x] = true;
                    x = p[x-1]; // Move to the next in the cycle, shift index for zero-based
                    cycle_length++;
                }

                // How many swaps are needed for this cycle to become simple
                if (cycle_length > 1) {
                    min_operations += cycle_length - 1;
                }
            }
        }

        return min_operations;
    }
};


#endif