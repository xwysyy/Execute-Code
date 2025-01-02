#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) { 
        vector<vector<int>> grid(2, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            grid[0][i] = (s1[i] == '.');
            grid[1][i] = (s2[i] == '.');
        }

        auto isConnected = [&](int row, int col) {
            if (col > 0 && grid[row][col - 1]) return true;
            if (row > 0 && grid[row - 1][col]) return true;
            if (col < n - 1 && grid[row][col + 1]) return true;
            if (row < 1 && grid[row + 1][col]) return true;
            return false;
        };

        int result = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    grid[i][j] = 0; // Block the cell
                    int components = 0;

                    for (int r = 0; r < 2; ++r) {
                        for (int c = 0; c < n; ++c) {
                            if (grid[r][c]) {
                                stack<pair<int, int>> st;
                                st.push({r, c});
                                while (!st.empty()) {
                                    auto [r, c] = st.top();
                                    st.pop();
                                    grid[r][c] = 0;
                                    if (c > 0 && grid[r][c - 1]) st.push({r, c - 1});
                                    if (r > 0 && grid[r - 1][c]) st.push({r - 1, c});
                                    if (c < n - 1 && grid[r][c + 1]) st.push({r, c + 1});
                                    if (r < 1 && grid[r + 1][c]) st.push({r + 1, c});
                                }
                                ++components;
                            }
                        }
                    }

                    if (components == 3) {
                        ++result;
                    }

                    grid[i][j] = 1; // Un-block the cell
                }
            }
        }

        return result;
    }
};

#endif