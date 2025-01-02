#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, vector<vector<int>> &a) {
        if (n == 0 || m == 0)
            return 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxVolume = 0;

        vector<int> directions = {-1, 0, 1, 0, -1};  // Directions array for NSWE movements

        function<int(int, int)> dfs = [&](int x, int y) {
            // Boundary check and zero cell check
            if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || a[x][y] == 0)
                return 0;

            // Mark current cell as visited
            visited[x][y] = true;
            int volume = a[x][y];

            // Explore in all 4 directions
            for (int i = 0; i < 4; ++i) {
                volume += dfs(x + directions[i], y + directions[i + 1]);
            }

            return volume;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && a[i][j] > 0) {
                    // Calculate the volume of the lake starting from (i, j)
                    int currentVolume = dfs(i, j);
                    maxVolume = max(maxVolume, currentVolume);
                }
            }
        }

        return maxVolume;
    }
};


#endif