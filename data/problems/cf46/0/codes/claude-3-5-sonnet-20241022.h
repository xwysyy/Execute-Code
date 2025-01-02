#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<bool>> grid;
    int rows = 2, cols;
    
    // Direction arrays for adjacent cells
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    // DFS to mark connected components
    void dfs(int x, int y, vector<vector<bool>>& visited) {
        visited[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && 
                !visited[nx][ny] && grid[nx][ny]) {
                dfs(nx, ny, visited);
            }
        }
    }
    
    // Count number of connected regions
    int countRegions() {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int regions = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid[i][j]) {
                    regions++;
                    dfs(i, j, visited);
                }
            }
        }
        
        return regions;
    }

public:
    int solve(int& n, string& s1, string& s2) {
        cols = n;
        // Convert strings to grid
        grid = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for (int j = 0; j < cols; j++) {
            grid[0][j] = (s1[j] == '.');
            grid[1][j] = (s2[j] == '.');
        }
        
        int result = 0;
        
        // For each free cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    // Temporarily block this cell
                    grid[i][j] = false;
                    
                    // Check if blocking creates exactly 3 regions
                    if (countRegions() == 3) {
                        result++;
                    }
                    
                    // Restore the cell
                    grid[i][j] = true;
                }
            }
        }
        
        return result;
    }
};


#endif