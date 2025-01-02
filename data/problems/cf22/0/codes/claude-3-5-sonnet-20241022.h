#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // DFS to explore lake and calculate its volume
    int dfs(vector<vector<int>>& a, vector<vector<bool>>& visited, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || a[i][j] == 0) {
            return 0;
        }
        
        visited[i][j] = true;
        int volume = a[i][j];
        
        // Explore in all 4 directions
        volume += dfs(a, visited, i+1, j, n, m);  // down
        volume += dfs(a, visited, i-1, j, n, m);  // up
        volume += dfs(a, visited, i, j+1, n, m);  // right
        volume += dfs(a, visited, i, j-1, n, m);  // left
        
        return volume;
    }

public:
    int solve(int &n, int &m, vector<vector<int>> &a) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxVolume = 0;
        
        // Explore each unvisited cell
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