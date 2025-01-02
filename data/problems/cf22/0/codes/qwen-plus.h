#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
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
        
        function<int(int, int)> dfs = [&](int x, int y) {
            if (!isValid(x, y)) return 0;
            visited[x][y] = true;
            int volume = a[x][y];
            static const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            for (const auto& [dx, dy] : directions) {
                volume += dfs(x + dx, y + dy);
            }
            return volume;
        };
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] > 0 && !visited[i][j]) {
                    maxVolume = max(maxVolume, dfs(i, j));
                }
            }
        }
        
        return maxVolume;
    }
};


#endif