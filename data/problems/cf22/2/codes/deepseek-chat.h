#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, vector<vector<int>> &a) {
        int maxVolume = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] > 0 && !visited[i][j]) {
                    int volume = 0;
                    dfs(i, j, a, visited, volume);
                    maxVolume = max(maxVolume, volume);
                }
            }
        }
        
        return maxVolume;
    }
    
private:
    void dfs(int i, int j, vector<vector<int>> &a, vector<vector<bool>> &visited, int &volume) {
        if (i < 0 || i >= a.size() || j < 0 || j >= a[0].size() || a[i][j] == 0 || visited[i][j]) {
            return;
        }
        
        visited[i][j] = true;
        volume += a[i][j];
        
        dfs(i + 1, j, a, visited, volume);
        dfs(i - 1, j, a, visited, volume);
        dfs(i, j + 1, a, visited, volume);
        dfs(i, j - 1, a, visited, volume);
    }
};


#endif