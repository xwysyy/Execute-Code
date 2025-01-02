#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, vector<vector<int>> &a) {   
        int maxVolume = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == 0 || visited[i][j]) {
                return 0;
            }
            visited[i][j] = true;
            int volume = a[i][j];
            volume += dfs(i + 1, j);
            volume += dfs(i - 1, j);
            volume += dfs(i, j + 1);
            volume += dfs(i, j - 1);
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