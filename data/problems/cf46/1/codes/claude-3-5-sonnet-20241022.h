#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<bool>> grid;
    int rows = 2, cols;
    
    // Check if cell is within grid bounds
    bool isValid(int i, int j) {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }
    
    // DFS to find connected components
    void dfs(int i, int j, vector<vector<bool>>& visited) {
        if (!isValid(i, j) || visited[i][j] || !grid[i][j]) return;
        
        visited[i][j] = true;
        
        // Check all 4 directions
        int di[] = {-1, 1, 0, 0};
        int dj[] = {0, 0, -1, 1};
        
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            dfs(ni, nj, visited);
        }
    }
    
    // Count number of connected components
    int countRegions() {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int regions = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    dfs(i, j, visited);
                    regions++;
                }
            }
        }
        return regions;
    }
    
    int solve(int& n, string& s1, string& s2) {
        cols = n;
        grid = vector<vector<bool>>(rows, vector<bool>(cols, false));
        
        // Convert strings to grid (true for free, false for blocked)
        for (int j = 0; j < cols; j++) {
            grid[0][j] = (s1[j] == '.');
            grid[1][j] = (s2[j] == '.');
        }
        
        int result = 0;
        
        // Try blocking each free cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {  // if cell is free
                    grid[i][j] = false;  // block it temporarily
                    if (countRegions() == 3) {
                        result++;
                    }
                    grid[i][j] = true;  // unblock it
                }
            }
        }
        
        return result;
    }
};


#endif