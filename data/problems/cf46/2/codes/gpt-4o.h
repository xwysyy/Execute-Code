#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::string &s1, std::string &s2) { 
        int result = 0;
        
        // Helper function to check if blocking a specific cell can split the grid into exactly 3 regions
        auto can_split_into_three = [&](int i, int j) {
            // Use a visited marker to explore the grid
            std::vector<std::vector<bool>> visited(2, std::vector<bool>(n, false));
            int regions = 0;

            // lambda function to perform DFS
            std::function<void(int, int)> dfs = [&](int row, int col) {
                if (row < 0 || row > 1 || col < 0 || col >= n || visited[row][col] || 
                    (row == i && col == j) || (row == 0 ? s1[col] : s2[col]) == 'x')
                    return;
                visited[row][col] = true;

                // Explore all 4 possible directions
                dfs(row + 1, col); // down
                dfs(row - 1, col); // up
                dfs(row, col + 1); // right
                dfs(row, col - 1); // left
            };

            // Try to find all connected regions
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < n; ++y) {
                    if (!visited[x][y] && (x != i || y != j) && 
                        (x == 0 ? s1[y] : s2[y]) == '.') {
                        dfs(x, y);
                        ++regions;
                    }
                }
            }

            return regions == 3; // Check if number of regions is exactly 3
        };
        
        // Check each free cell, if it can be a critical point
        for (int row = 0; row < 2; ++row) {
            for (int col = 0; col < n; ++col) {
                if ((row == 0 ? s1[col] : s2[col]) == '.') {
                    // Check if blocking this cell splits into 3 regions
                    if (can_split_into_three(row, col)) {
                        result += 1;
                    }
                }
            }
        }

        return result;
    }
};


#endif