#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        // State: {row, col, last_move, time}
        // last_move: 0=skip, 1=up, 2=down, 3=right, 4=left
        queue<vector<int>> q;
        
        // Set to keep track of visited states
        set<vector<int>> visited;
        
        // Start from (0,0) with no previous move (-1)
        q.push({0, 0, -1, 0});
        
        // Possible moves: skip, up, down, right, left
        vector<pair<int, int>> moves = {{0,0}, {1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int row = curr[0], col = curr[1];
            int last_move = curr[2], time = curr[3];
            
            // If we reached the target
            if (row == a && col == b) {
                return time;
            }
            
            // Try all possible moves
            for (int move = 0; move < 5; move++) {
                // Skip if this move is same as last move
                if (move == last_move) continue;
                
                int new_row = row + moves[move].first;
                int new_col = col + moves[move].second;
                
                // Check if new position is within bounds
                if (new_row >= -n && new_row <= n && 
                    new_col >= -n && new_col <= n) {
                    
                    vector<int> new_state = {new_row, new_col, move};
                    
                    // If this state hasn't been visited
                    if (visited.find(new_state) == visited.end()) {
                        visited.insert(new_state);
                        q.push({new_row, new_col, move, time + 1});
                    }
                }
            }
        }
        
        return -1; // Should never reach here given constraints
    }
};


#endif