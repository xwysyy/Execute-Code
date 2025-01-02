#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, vector<vector<int>> &a) {
        if (n == 0 || m == 0) return 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxVolume = 0;

        // Direction vectors for moving up, down, left, right
        vector<int> dirX = {0, 0, 1, -1};
        vector<int> dirY = {1, -1, 0, 0};

        auto isValid = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && a[x][y] > 0;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] > 0 && !visited[i][j]) {
                    // New lake found, perform DFS
                    int currentVolume = 0;
                    stack<pair<int, int>> s;
                    s.push({i, j});

                    while (!s.empty()) {
                        auto [x, y] = s.top();
                        s.pop();

                        if (visited[x][y]) continue;
                        visited[x][y] = true;
                        currentVolume += a[x][y];

                        // Check all 4 directions
                        for (int d = 0; d < 4; ++d) {
                            int newX = x + dirX[d];
                            int newY = y + dirY[d];
                            if (isValid(newX, newY)) {
                                s.push({newX, newY});
                            }
                        }
                    }

                    maxVolume = max(maxVolume, currentVolume);
                }
            }
        }

        return maxVolume;
    }
};


#endif