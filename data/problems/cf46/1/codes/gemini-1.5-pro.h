#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                if (j == 0 && s1[i] == '.') {
                    s1[i] = 'x';
                    if (count_regions(n, s1, s2) == 3) {
                        ans++;
                    }
                    s1[i] = '.';
                } else if (j == 1 && s2[i] == '.') {
                    s2[i] = 'x';
                    if (count_regions(n, s1, s2) == 3) {
                        ans++;
                    }
                    s2[i] = '.';
                }
            }
        }
        return ans;
    }

private:
    int count_regions(int n, string &s1, string &s2) {
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        int regions = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 && s1[j] == '.') || (i == 1 && s2[j] == '.')) {
                    if (!visited[i][j]) {
                        regions++;
                        dfs(i, j, n, s1, s2, visited);
                    }
                }
            }
        }
        return regions;
    }

    void dfs(int r, int c, int n, string &s1, string &s2, vector<vector<bool>> &visited) {
        if (r < 0 || r >= 2 || c < 0 || c >= n || visited[r][c] || (r == 0 && s1[c] == 'x') || (r == 1 && s2[c] == 'x')) {
            return;
        }
        visited[r][c] = true;
        dfs(r + 1, c, n, s1, s2, visited);
        dfs(r - 1, c, n, s1, s2, visited);
        dfs(r, c + 1, n, s1, s2, visited);
        dfs(r, c - 1, n, s1, s2, visited);
    }
};


#endif