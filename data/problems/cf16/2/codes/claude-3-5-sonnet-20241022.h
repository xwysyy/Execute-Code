#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        // Define possible moves: skip, up, down, right, left
        const vector<pair<int, int>> moves = {{0,0}, {1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // Queue will store: {{row, col}, {time, lastMove}}
        queue<pair<pair<int,int>, pair<int,int>>> q;
        
        // visited[row+n][col+n][lastMove] to track visited states
        vector<vector<vector<bool>>> visited(2*n+1, 
            vector<vector<bool>>(2*n+1, vector<bool>(5, false)));
        
        // Start from (0,0) with no previous move (-1)
        q.push({{0,0}, {0,-1}});
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int row = curr.first.first;
            int col = curr.first.second;
            int time = curr.second.first;
            int lastMove = curr.second.second;
            
            // If we reached target
            if (row == a && col == b) {
                return time;
            }
            
            // Try all possible moves
            for (int move = 0; move < 5; move++) {
                // Can't use same move twice in a row
                if (move == lastMove) continue;
                
                int newRow = row + moves[move].first;
                int newCol = col + moves[move].second;
                
                // Check if new position is valid and not visited
                if (newRow >= -n && newRow <= n && 
                    newCol >= -n && newCol <= n && 
                    !visited[newRow+n][newCol+n][move]) {
                    
                    visited[newRow+n][newCol+n][move] = true;
                    q.push({{newRow,newCol}, {time+1,move}});
                }
            }
        }
        
        return -1; // Should never reach here given constraints
    }
};


#endif