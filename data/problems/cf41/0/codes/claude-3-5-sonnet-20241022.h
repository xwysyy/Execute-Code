#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {
        vector<int> result(q);
        
        // Process each query independently
        for (int i = 0; i < q; i++) {
            // Create a vector to track players (1 = present, 0 = eliminated)
            vector<bool> players(n[i], true);
            int remaining = n[i];
            bool changed;
            
            // Continue rounds until no changes occur
            do {
                changed = false;
                int pos = 0;  // Current position in line
                int count = 0;  // Count of players seen
                
                // Check each position that needs to be eliminated
                for (int j = 0; j < k; j++) {
                    int target = a[j];
                    pos = 0;
                    count = 0;
                    
                    // Find the target-th remaining player
                    while (pos < n[i] && count < target) {
                        if (players[pos]) count++;
                        pos++;
                    }
                    
                    // If we found the target position and player hasn't been eliminated
                    if (count == target && pos > 0 && players[pos-1]) {
                        players[pos-1] = false;
                        remaining--;
                        changed = true;
                    }
                }
            } while (changed && remaining > 0);
            
            result[i] = remaining;
        }
        
        return result;
    }
};


#endif