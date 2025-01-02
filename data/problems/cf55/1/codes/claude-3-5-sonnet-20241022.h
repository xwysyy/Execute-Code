#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        // Convert to 0-based indexing
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = p[i] - 1;
        }
        
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;
            
            // Start a new component
            vector<int> cycle;
            int curr = i;
            while(!visited[curr]) {
                visited[curr] = true;
                cycle.push_back(curr);
                curr = a[curr];
            }
            
            // For each component:
            // - If size is 1, it's already fixed
            // - If size is 2, it's already a valid cycle
            // - For larger sizes, we need (size-1) swaps to break into valid cycles
            if(cycle.size() > 2) {
                swaps += cycle.size() - 1;
            }
        }
        
        return swaps;
    }
};


#endif