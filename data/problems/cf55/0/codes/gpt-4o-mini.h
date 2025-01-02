#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        vector<bool> visited(n + 1, false); // To keep track of visited elements
        int swaps = 0; // Count of swaps needed

        // Iterate over each index
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) { // If we haven't visited this index yet
                int cycle_length = 0;
                int current = i;

                // Trace the cycle
                while (!visited[current]) {
                    visited[current] = true; // Mark as visited
                    current = p[current - 1]; // Move to the next in the cycle
                    cycle_length++;
                }

                // Each cycle of length k requires (k - 1) swaps to fix
                if (cycle_length > 0) {
                    swaps += (cycle_length - 1);
                }
            }
        }
        
        return swaps; // Return total number of swaps needed
    }
};


#endif