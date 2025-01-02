#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // A visited matrix to keep track of visited cells
        vector<vector<bool>> visited(2, vector<bool>(n, false));

        // Queue for BFS
        vector<pair<int, int>> queue;
        queue.push_back({0, 0});  // Starting at (1, 1) which is (0, 0) in 0-indexed

        // Directions: Right, Left, Move within the same column Down, Move within the same column Up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!queue.empty()) {
            int r = queue.back().first;
            int c = queue.back().second;
            queue.pop_back();
            
            // If we reach (2, n) i.e., r is 1 and c is n-1
            if (r == 1 && c == n - 1) return "YES";

            // Check visited
            if (visited[r][c]) continue;
            visited[r][c] = true;
            
            // Move in the direction of the arrow
            char direction = (r == 0) ? s1[c] : s2[c];
            
            // Move according to the current cell arrow
            if (direction == '>') {
                if (c + 1 < n && !visited[r][c + 1]) {
                    queue.push_back({r, c + 1});
                }
            } else if (direction == '<') {
                if (c - 1 >= 0 && !visited[r][c - 1]) {
                    queue.push_back({r, c - 1});
                }
            } 
            
            // Move to the opposite row using vertical transition
            // This transition doesn't require following arrow direction
            if (c + 1 < n && !visited[1 - r][c]) {
                queue.push_back({1 - r, c});
            }
        }

        return "NO"; // If no way to reach (2, n)
    }
};


#endif