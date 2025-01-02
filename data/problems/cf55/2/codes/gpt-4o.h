#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        vector<bool> visited(n, false);
        int min_swaps = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int cycle_length = 0;
                int current = i;

                // Traverse the cycle
                while (!visited[current]) {
                    visited[current] = true;
                    current = p[current] - 1; // Move to the next index in the cycle
                    cycle_length++;
                }

                if (cycle_length > 1) {
                    // To transform such a cycle, we need (cycle_length - 1) swaps
                    min_swaps += (cycle_length - 1);
                }
            }
        }
        
        return min_swaps;
    }
};


#endif