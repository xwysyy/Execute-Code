#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &m, vector<vector<int>> &a)
    {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && a[i][j] > 0)
                {
                    int res = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    while (!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();
                        res += a[x][y];
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] > 0 && !vis[nx][ny])
                            {
                                q.push({nx, ny});
                                vis[nx][ny] = true;
                            }
                        }
                    }
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }
};



#endif