#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Store visited states to detect cycles
        set<pair<int, int>> visited;
        
        // Start DFS from position (0,0)
        if (canReachEnd(0, 0, n, s1, s2, visited))
            return "YES";
        return "NO";
    }
    
private:
    bool canReachEnd(int row, int col, int n, string &s1, string &s2, 
                     set<pair<int, int>> &visited) {
        // Check if we reached destination
        if (row == 1 && col == n-1)
            return true;
            
        // If state already visited, return false to avoid cycles
        if (visited.count({row, col}))
            return false;
            
        // Mark current state as visited
        visited.insert({row, col});
        
        // Try all possible moves
        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto [dr, dc] : moves) {
            int newRow = row + dr;
            int newCol = col + dc;
            
            // Check if move is valid
            if (newRow < 0 || newRow > 1 || newCol < 0 || newCol >= n)
                continue;
                
            // Get arrow direction in new cell
            char arrow = (newRow == 0) ? s1[newCol] : s2[newCol];
            int finalCol = newCol + (arrow == '>' ? 1 : -1);
            
            // Check if arrow move is valid
            if (finalCol < 0 || finalCol >= n)
                continue;
                
            // Try this path
            if (canReachEnd(newRow, finalCol, n, s1, s2, visited))
                return true;
        }
        
        return false;
    }
};


#endif