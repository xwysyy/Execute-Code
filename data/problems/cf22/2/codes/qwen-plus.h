#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, vector<vector<int>> &a) {   
        int largestVolume = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        function<int(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == 0 || visited[x][y]) {
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
                    largestVolume = max(largestVolume, dfs(i, j));
                }
            }
        }
        
        return largestVolume;
    }
};


#endif