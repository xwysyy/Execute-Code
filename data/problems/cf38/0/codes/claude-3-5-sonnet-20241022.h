#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {
        // Use set to track possible positions after each throw
        set<int> positions = {x};
        
        // Process each throw
        for (int i = 0; i < m; i++) {
            set<int> new_positions;
            int dist = a[i].first;
            char dir = a[i].second;
            
            // For each current possible position
            for (int pos : positions) {
                // Calculate new positions based on direction
                if (dir == '?' || dir == '0') {
                    // Clockwise
                    int new_pos = pos + dist;
                    if (new_pos > n) new_pos = new_pos - n;
                    new_positions.insert(new_pos);
                }
                if (dir == '?' || dir == '1') {
                    // Counterclockwise
                    int new_pos = pos - dist;
                    if (new_pos <= 0) new_pos = new_pos + n;
                    new_positions.insert(new_pos);
                }
            }
            positions = new_positions;
        }
        
        // Return number of possible final positions
        return positions.size();
    }
};


#endif