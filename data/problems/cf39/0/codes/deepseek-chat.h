#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // The robot starts at (1, 1)
        // We need to simulate the robot's movement
        // The robot can move in four directions (left, right, down, up)
        // but it cannot go outside the grid or skip a move
        // After moving, it follows the arrow in the current cell

        // Since the grid is 2 rows and n columns, we can represent the positions as (row, col)
        // row: 1 or 2
        // col: 1 to n

        // We will use BFS to explore all possible paths
        // We will keep track of visited positions to avoid infinite loops

        // Initialize the queue with the starting position
        queue<pair<int, int>> q;
        q.push({1, 1});

        // Initialize a visited array
        vector<vector<bool>> visited(3, vector<bool>(n + 1, false));
        visited[1][1] = true;

        // Directions for movement: left, right, down, up
        int dirRow[] = {0, 0, 1, -1};
        int dirCol[] = {-1, 1, 0, 0};

        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            int row = current.first;
            int col = current.second;

            // Check if we have reached the destination
            if (row == 2 && col == n) {
                return "YES";
            }

            // Try all four possible moves
            for (int i = 0; i < 4; i++) {
                int newRow = row + dirRow[i];
                int newCol = col + dirCol[i];

                // Check if the new position is within the grid and not visited
                if (newRow >= 1 && newRow <= 2 && newCol >= 1 && newCol <= n && !visited[newRow][newCol]) {
                    // Move to the new position
                    visited[newRow][newCol] = true;

                    // Follow the arrow in the new position
                    char arrow = (newRow == 1) ? s1[newCol - 1] : s2[newCol - 1];
                    if (arrow == '>') {
                        newCol++;
                    } else {
                        newCol--;
                    }

                    // Check if the final position after following the arrow is within the grid and not visited
                    if (newCol >= 1 && newCol <= n && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        // If we exhaust all possibilities and haven't reached the destination, return "NO"
        return "NO";
    }
};


#endif