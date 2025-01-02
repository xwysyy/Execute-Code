#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Create a set to store visited states (position and initial move)
        set<pair<pair<int, int>, int>> visited;
        // Queue for BFS: {{row, col}, last_move}
        // last_move: 0=left, 1=right, 2=up, 3=down
        queue<pair<pair<int, int>, int>> q;
        
        // Start from (0,0) and try all possible initial moves
        for(int move = 0; move < 4; move++) {
            q.push({{0, 0}, move});
            visited.insert({{0, 0}, move});
        }
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int row = curr.first.first;
            int col = curr.first.second;
            int move = curr.second;
            
            // First move according to robot's choice
            int new_row = row;
            int new_col = col;
            if(move == 0) new_col--; // left
            else if(move == 1) new_col++; // right
            else if(move == 2) new_row--; // up
            else new_row++; // down
            
            // Check if move is valid
            if(new_row < 0 || new_row > 1 || new_col < 0 || new_col >= n)
                continue;
                
            // Then move according to arrow
            string& curr_row = (new_row == 0) ? s1 : s2;
            new_col += (curr_row[new_col] == '<' ? -1 : 1);
            
            // Check if arrow move is valid
            if(new_col < 0 || new_col >= n)
                continue;
                
            // Check if we reached destination
            if(new_row == 1 && new_col == n-1)
                return "YES";
                
            // Try all possible next moves
            for(int next_move = 0; next_move < 4; next_move++) {
                if(visited.find({{new_row, new_col}, next_move}) == visited.end()) {
                    visited.insert({{new_row, new_col}, next_move});
                    q.push({{new_row, new_col}, next_move});
                }
            }
        }
        
        return "NO";
    }
};


#endif