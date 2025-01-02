#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, vector<vector<int>> &a) {
        int largestVolume = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // Directions for moving up, down, left, right
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        auto isValid = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m && 
                   a[x][y] > 0 && !visited[x][y];
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] > 0 && !visited[i][j]) {
                    // Start a new lake
                    int volume = 0;
                    stack<pair<int, int>> s;
                    s.push({i, j});
                    visited[i][j] = true;

                    while (!s.empty()) {
                        auto [x, y] = s.top();
                        s.pop();
                        volume += a[x][y];

                        // Check the four possible directions
                        for (auto& dir : directions) {
                            int nx = x + dir[0], ny = y + dir[1];
                            if (isValid(nx, ny)) {
                                visited[nx][ny] = true;
                                s.push({nx, ny});
                            }
                        }
                    }
                    largestVolume = max(largestVolume, volume);
                }
            }
        }
        return largestVolume;
    }
};


#endif