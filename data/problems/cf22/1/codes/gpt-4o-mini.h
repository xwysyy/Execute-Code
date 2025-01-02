#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, vector<vector<int>> &a) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int max_volume = 0;

        // Directions for up, down, left, right movements
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Function to perform DFS to explore each lake
        auto dfs = [&](int x, int y, auto&& dfs_ref) -> int {
            if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == 0 || visited[x][y]) {
                return 0;
            }
            visited[x][y] = true;
            int volume = a[x][y];
            for (const auto& dir : directions) {
                volume += dfs_ref(x + dir.first, y + dir.second, dfs_ref);
            }
            return volume;
        };

        // Iterate through the entire grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] > 0 && !visited[i][j]) { // Found a new lake
                    int current_volume = dfs(i, j, dfs);
                    max_volume = max(max_volume, current_volume);
                }
            }
        }
        
        return max_volume;
    }
};


#endif