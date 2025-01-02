#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        vector<bool> visited(n, false);
        int swaps = 0;
        
        // Convert to 0-based indexing
        for (int i = 0; i < n; i++) {
            p[i]--;
        }
        
        // Process each element
        for (int i = 0; i < n; i++) {
            if (visited[i] || p[i] == i) continue;
            
            // Find cycle size
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = p[j];
                cycle_size++;
            }
            
            // For each cycle, we need (cycle_size - 1) swaps
            // or (cycle_size + 1) swaps if we want to make all elements fixed points
            swaps += min(cycle_size - 1, cycle_size + 1);
        }
        
        return swaps;
    }
};


#endif