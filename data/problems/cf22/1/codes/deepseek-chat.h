#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, vector<vector<int>> &a) {
        if (n == 0 || m == 0) return 0;
        
        int maxVolume = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] > 0 && !visited[i][j]) {
                    int volume = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while (!q.empty()) {
                        auto current = q.front();
                        q.pop();
                        int x = current.first;
                        int y = current.second;
                        volume += a[x][y];
                        
                        // Check all four directions
                        if (x > 0 && a[x-1][y] > 0 && !visited[x-1][y]) {
                            visited[x-1][y] = true;
                            q.push({x-1, y});
                        }
                        if (x < n-1 && a[x+1][y] > 0 && !visited[x+1][y]) {
                            visited[x+1][y] = true;
                            q.push({x+1, y});
                        }
                        if (y > 0 && a[x][y-1] > 0 && !visited[x][y-1]) {
                            visited[x][y-1] = true;
                            q.push({x, y-1});
                        }
                        if (y < m-1 && a[x][y+1] > 0 && !visited[x][y+1]) {
                            visited[x][y+1] = true;
                            q.push({x, y+1});
                        }
                    }
                    
                    maxVolume = max(maxVolume, volume);
                }
            }
        }
        
        return maxVolume;
    }
};


#endif