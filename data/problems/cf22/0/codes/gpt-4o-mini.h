#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, vector<vector<int>> &a) {
        int maxVolume = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        auto isValid = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m && a[x][y] > 0 && !visited[x][y];
        };

        auto dfs = [&](int x, int y, auto&& dfsRef) -> int {
            visited[x][y] = true;
            int volume = a[x][y];

            // Directions for moving in the grid (up, down, left, right)
            int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;
                if (isValid(newX, newY)) {
                    volume += dfsRef(newX, newY, dfsRef);
                }
            }
            return volume;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] > 0 && !visited[i][j]) {
                    int lakeVolume = dfs(i, j, dfs);
                    maxVolume = max(maxVolume, lakeVolume);
                }
            }
        }
        
        return maxVolume;
    }
};


#endif