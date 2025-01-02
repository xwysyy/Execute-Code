#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) {
        // Function to count connected components of free cells
        auto countComponents = [&](bool blockRow1, int col) {
            vector<vector<bool>> visited(2, vector<bool>(n, false));
            if (blockRow1) visited[0][col] = true; 
            else visited[1][col] = true;

            int componentCount = 0;

            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < n; ++j) {
                    if ((s1[i] == '.' && i == 0 && !visited[0][j]) || 
                        (s2[i] == '.' && i == 1 && !visited[1][j])) {
                        // Start a new component search
                        ++componentCount;
                        // Perform DFS or BFS to mark all reachable cells
                        stack<pair<int, int>> stk;
                        stk.push({i, j});
                        while (!stk.empty()) {
                            auto [x, y] = stk.top();
                            stk.pop();
                            if (visited[x][y]) continue; // Already visited
                            visited[x][y] = true; // Mark the cell as visited
                            // Explore neighbors
                            if (y > 0 && !visited[x][y - 1] && ((x == 0 && s1[y - 1] == '.') || (x == 1 && s2[y - 1] == '.'))) {
                                stk.push({x, y - 1});
                            }
                            if (y < n - 1 && !visited[x][y + 1] && ((x == 0 && s1[y + 1] == '.') || (x == 1 && s2[y + 1] == '.'))) {
                                stk.push({x, y + 1});
                            }
                            if (x == 0 && !visited[1][y] && s2[y] == '.') {
                                stk.push({1, y});
                            } else if (x == 1 && !visited[0][y] && s1[y] == '.') {
                                stk.push({0, y});
                            }
                        }
                    }
                }
            }
            return componentCount;
        };

        int freeCellCount = 0;

        for (int i = 0; i < n; ++i) {
            if (s1[i] == '.') {
                // Temporarily block s1[i] and check the number of components
                int components = countComponents(true, i);
                if (components == 3) {
                    ++freeCellCount;
                }
            }
            if (s2[i] == '.') {
                // Temporarily block s2[i] and check the number of components
                int components = countComponents(false, i);
                if (components == 3) {
                    ++freeCellCount;
                }
            }
        }

        return freeCellCount;
    }
};


#endif