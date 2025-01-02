#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        // Convert to 0-based indexing for easier handling
        for (int i = 0; i < n; i++) {
            p[i]--;
        }
        
        int swaps = 0;
        vector<bool> visited(n, false);
        
        // Check each position
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            
            // If already satisfies condition 1 or 2, mark as visited
            if (p[i] == i || p[p[i]] == i) {
                visited[i] = true;
                if (p[i] != i) visited[p[i]] = true;
                continue;
            }
            
            // Find the best position to swap with
            int best_pos = -1;
            int min_additional_swaps = n;
            
            // Try swapping with each unvisited position
            for (int j = i + 1; j < n; j++) {
                if (visited[j]) continue;
                
                // Try swap p[i] and p[j]
                swap(p[i], p[j]);
                
                int additional_swaps = 0;
                // Check if positions i and j become valid after swap
                if (!(p[i] == i || p[p[i]] == i)) additional_swaps++;
                if (!(p[j] == j || p[p[j]] == j)) additional_swaps++;
                
                if (additional_swaps < min_additional_swaps) {
                    min_additional_swaps = additional_swaps;
                    best_pos = j;
                }
                
                // Restore the permutation
                swap(p[i], p[j]);
            }
            
            // If found a better position, perform the swap
            if (best_pos != -1) {
                swap(p[i], p[best_pos]);
                swaps++;
                visited[i] = true;
                visited[best_pos] = true;
            }
        }
        
        // Convert back to 1-based indexing
        for (int i = 0; i < n; i++) {
            p[i]++;
        }
        
        return swaps;
    }
};


#endif