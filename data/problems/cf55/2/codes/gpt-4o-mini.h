#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        vector<bool> visited(n + 1, false); // Visited array to track processed indices
        int swaps = 0; // To count minimum swaps required
        
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                // New cycle detected
                int cycleLength = 0;
                int current = i;
                
                // Traverse the current cycle
                while (!visited[current]) {
                    visited[current] = true;
                    current = p[current - 1]; // Move to the next index in the permutation
                    cycleLength++;
                }
                
                // If cycleLength > 1, we need (cycleLength - 1) swaps to fix this cycle
                if (cycleLength > 1) {
                    swaps += (cycleLength - 1);
                }
            }
        }
        
        return swaps;
    }
};


#endif