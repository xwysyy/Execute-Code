#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Create visited array to track cells we've already checked
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        
        // If starting position or target position has trap, return "NO"
        if (s1[0] == '1' || s2[n-1] == '1') return "NO";
        
        // DFS from starting position (0,0)
        if (dfs(0, 0, n, s1, s2, visited)) {
            return "YES";
        }
        return "NO";
    }
    
private:
    bool dfs(int row, int col, int n, string& s1, string& s2, vector<vector<bool>>& visited) {
        // If we reached the target cell
        if (row == 1 && col == n-1) return true;
        
        // Mark current cell as visited
        visited[row][col] = true;
        
        // Try all possible moves (including diagonals)
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                int newRow = row + dr;
                int newCol = col + dc;
                
                // Check if new position is valid
                if (newRow >= 0 && newRow < 2 && newCol >= 0 && newCol < n) {
                    // Skip if cell is already visited or has trap
                    if (visited[newRow][newCol]) continue;
                    if ((newRow == 0 && s1[newCol] == '1') || 
                        (newRow == 1 && s2[newCol] == '1')) continue;
                    
                    if (dfs(newRow, newCol, n, s1, s2, visited)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};


#endif