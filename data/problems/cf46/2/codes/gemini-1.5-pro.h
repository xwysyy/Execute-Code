#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '.' && s2[i] == '.') {
                string temp_s1 = s1;
                string temp_s2 = s2;
                temp_s1[i] = 'x';
                temp_s2[i] = 'x';
                if (connected_regions(n, temp_s1, temp_s2) == 3) {
                    count++;
                }
            }
        }
        return count;
    }

private:
    int connected_regions(int n, string &s1, string &s2) {
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        int regions = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((s1[j] == '.' && i == 0 || s2[j] == '.' && i == 1) && !visited[i][j]) {
                    regions++;
                    dfs(n, s1, s2, visited, i, j);
                }
            }
        }
        return regions;
    }

    void dfs(int n, string &s1, string &s2, vector<vector<bool>> &visited, int r, int c) {
        if (r < 0 || r >= 2 || c < 0 || c >= n || visited[r][c] || (s1[c] == 'x' && r == 0) || (s2[c] == 'x' && r == 1)) {
            return;
        }
        visited[r][c] = true;
        dfs(n, s1, s2, visited, r + 1, c);
        dfs(n, s1, s2, visited, r - 1, c);
        dfs(n, s1, s2, visited, r, c + 1);
        dfs(n, s1, s2, visited, r, c - 1);
    }
};


#endif