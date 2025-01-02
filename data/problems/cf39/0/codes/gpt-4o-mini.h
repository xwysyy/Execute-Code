#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Possible positions in the format (row, column)
        queue<pair<int, int>> q;
        // We will store visited positions to avoid cycles
        unordered_set<string> visited;
        
        // Start from position (1, 1)
        q.push({1, 1});
        visited.insert("1,1"); // Mark (1,1) as visited
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            // If we've reached (2, n), return "YES"
            if (row == 2 && col == n) {
                return "YES";
            }
            
            // Possible moves: down, up, right, left
            // 1. Move Down
            if (row == 1 && !visited.count("2," + to_string(col))) {
                // Move to (2, col)
                visited.insert("2," + to_string(col));
                q.push({2, col});
            }
            // 2. Move Up
            if (row == 2 && !visited.count("1," + to_string(col))) {
                // Move to (1, col)
                visited.insert("1," + to_string(col));
                q.push({1, col});
            }
            // 3. Move Right
            if (col < n) {
                if (row == 1 && s1[col - 1] == '>') {
                    // Move to (1, col + 1)
                    if (!visited.count("1," + to_string(col + 1))) {
                        visited.insert("1," + to_string(col + 1));
                        q.push({1, col + 1});
                    }
                }
                if (row == 2 && s2[col - 1] == '>') {
                    // Move to (2, col + 1)
                    if (!visited.count("2," + to_string(col + 1))) {
                        visited.insert("2," + to_string(col + 1));
                        q.push({2, col + 1});
                    }
                }
            }
            // 4. Move Left (but only if col > 1)
            if (col > 1) {
                if (row == 1 && s1[col - 2] == '<') {
                    // Move to (1, col - 1)
                    if (!visited.count("1," + to_string(col - 1))) {
                        visited.insert("1," + to_string(col - 1));
                        q.push({1, col - 1});
                    }
                }
                if (row == 2 && s2[col - 2] == '<') {
                    // Move to (2, col - 1)
                    if (!visited.count("2," + to_string(col - 1))) {
                        visited.insert("2," + to_string(col - 1));
                        q.push({2, col - 1});
                    }
                }
            }
        }
        
        // If we exit the while loop, we never reached (2, n), so return "NO"
        return "NO";
    }
};


#endif