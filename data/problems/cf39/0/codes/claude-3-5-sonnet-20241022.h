#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Create a set to store visited states (position and initial move)
        set<pair<pair<int, int>, int>> visited;
        // Queue for BFS: {{row, col}, initial_move}
        queue<pair<pair<int, int>, int>> q;
        
        // Start from (0,0) and try all possible initial moves
        q.push({{0, 0}, 0}); // 0: no initial move yet
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int row = curr.first.first;
            int col = curr.first.second;
            int move = curr.second;
            
            // If we've reached the target
            if (row == 1 && col == n-1) return "YES";
            
            // If we haven't made our initial move yet
            if (move == 0) {
                // Try all possible moves: right, down, up, left
                // Right
                if (col + 1 < n) {
                    pair<pair<int, int>, int> next = {{row, col + 1}, 1};
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
                // Down
                if (row < 1) {
                    pair<pair<int, int>, int> next = {{row + 1, col}, 1};
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
                // Up
                if (row > 0) {
                    pair<pair<int, int>, int> next = {{row - 1, col}, 1};
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
                // Left
                if (col > 0) {
                    pair<pair<int, int>, int> next = {{row, col - 1}, 1};
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            // After initial move, follow the arrow
            else {
                char arrow = (row == 0) ? s1[col] : s2[col];
                int nextCol = (arrow == '>') ? col + 1 : col - 1;
                
                // Check if the arrow movement is valid
                if (nextCol >= 0 && nextCol < n) {
                    pair<pair<int, int>, int> next = {{row, nextCol}, 0};
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        
        return "NO";
    }
};


#endif