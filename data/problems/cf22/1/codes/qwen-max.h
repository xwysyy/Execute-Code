#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, vector<vector<int>> &a) {
        int max_volume = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        function<int(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == 0 || visited[x][y]) {
                return 0;
            }
            visited[x][y] = true;
            int volume = a[x][y];
            volume += dfs(x + 1, y);
            volume += dfs(x - 1, y);
            volume += dfs(x, y + 1);
            volume += dfs(x, y - 1);
            return volume;
        };
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] > 0 && !visited[i][j]) {
                    max_volume = max(max_volume, dfs(i, j));
                }
            }
        }
        
        return max_volume;
    }
};

#endif