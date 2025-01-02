#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, std::vector<std::vector<int>> &a) {
        int max_volume = 0;
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        
        // Direction vectors for moving up, down, left, right
        std::vector<int> dr = {-1, 1, 0, 0};
        std::vector<int> dc = {0, 0, -1, 1};
        
        auto is_valid = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && a[x][y] > 0;
        };
        
        // DFS using stack
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] > 0 && !visited[i][j]) {
                    // New lake found; compute its volume using DFS
                    int lake_volume = 0;
                    std::stack<std::pair<int, int>> stk;
                    stk.push({i, j});
                    visited[i][j] = true;
                    
                    while (!stk.empty()) {
                        auto [x, y] = stk.top();
                        stk.pop();
                        lake_volume += a[x][y];
                        
                        for (int d = 0; d < 4; ++d) {
                            int nx = x + dr[d];
                            int ny = y + dc[d];
                            if (is_valid(nx, ny)) {
                                visited[nx][ny] = true;
                                stk.push({nx, ny});
                            }
                        }
                    }
                    
                    max_volume = std::max(max_volume, lake_volume);
                }
            }
        }
        return max_volume;
    }
};


#endif