#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) {
        int result = 0;
        bool connectedRegionExists = false;
        int freeCellsInRegion = 0;

        // Check if there is a connected region and count free cells in it
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '.' || s2[i] == '.') {
                connectedRegionExists = true;
                if (s1[i] == '.') ++freeCellsInRegion;
                if (s2[i] == '.') ++freeCellsInRegion;
            }
        }

        // If there is no connected region initially, return 0
        if (!connectedRegionExists) return 0;

        // Check each free cell to see if blocking it results in exactly 3 regions
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '.') {
                s1[i] = 'x';
                if (countRegions(n, s1, s2) == 3) {
                    ++result;
                }
                s1[i] = '.';
            }
            if (s2[i] == '.') {
                s2[i] = 'x';
                if (countRegions(n, s1, s2) == 3) {
                    ++result;
                }
                s2[i] = '.';
            }
        }

        return result;
    }

private:
    int countRegions(int n, const string &s1, const string &s2) {
        vector<bool> visited(n, false);
        int regions = 0;

        auto dfs = [&](auto &&dfs, int col, bool top) -> void {
            if (col < 0 || col >= n || visited[col]) return;
            char &cell = top ? s1[col] : s2[col];
            if (cell == 'x') return;
            visited[col] = true;
            if (top) {
                dfs(dfs, col, false); // Down
            } else {
                dfs(dfs, col, true); // Up
            }
            dfs(dfs, col - 1, top); // Left
            dfs(dfs, col + 1, top); // Right
        };

        for (int i = 0; i < n; ++i) {
            if (!visited[i] && (s1[i] == '.' || s2[i] == '.')) {
                ++regions;
                if (s1[i] == '.') dfs(dfs, i, true);
                if (s2[i] == '.' && !visited[i]) dfs(dfs, i, false);
            }
        }

        return regions;
    }
};


#endif