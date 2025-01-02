#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, vector<vector<int>> &a) {
        int maxVolume = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] > 0) {
                    int volume = 0;
                    dfs(i, j, a, volume);
                    if (volume > maxVolume) {
                        maxVolume = volume;
                    }
                }
            }
        }
        return maxVolume;
    }

private:
    void dfs(int i, int j, vector<vector<int>> &a, int &volume) {
        if (i < 0 || i >= a.size() || j < 0 || j >= a[0].size() || a[i][j] == 0) {
            return;
        }
        volume += a[i][j];
        a[i][j] = 0; // Mark as visited
        dfs(i + 1, j, a, volume);
        dfs(i - 1, j, a, volume);
        dfs(i, j + 1, a, volume);
        dfs(i, j - 1, a, volume);
    }
};


#endif