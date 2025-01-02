#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // DFS to find the volume of a lake starting from position (i,j)
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int n, int m) {
        // Check bounds and if cell is already visited or is 0
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == 0) {
            return 0;
        }
        
        visited[i][j] = true;
        int volume = grid[i][j];
        
        // Directions: up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        // Visit all adjacent cells
        for (int dir = 0; dir < 4; dir++) {
            int newX = i + dx[dir];
            int newY = j + dy[dir];
            volume += dfs(grid, visited, newX, newY, n, m);
        }
        
        return volume;
    }
    
public:
    int solve(int &n, int &m, vector<vector<int>> &a) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxVolume = 0;
        
        // Try starting DFS from each unvisited cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && a[i][j] > 0) {
                    maxVolume = max(maxVolume, dfs(a, visited, i, j, n, m));
                }
            }
        }
        
        return maxVolume;
    }
};


#endif