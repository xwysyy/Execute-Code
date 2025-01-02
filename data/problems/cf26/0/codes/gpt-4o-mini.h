#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        // Create a set to track friend positions
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // To store the count of friends located around Vika
        int friendCount = 0;

        for (const auto &friendPos : a) {
            int fx = friendPos.first;
            int fy = friendPos.second;

            // Check if the friend's position coincides with any of the neighboring cells of Vika
            // Vika's current position is (x, y)
            // Check all neighboring positions
            for (const auto &dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx == fx && ny == fy) {
                    friendCount++;
                }
            }
        }

        // If Vika has no friends in adjacent cells, she can run away
        if (friendCount == 0) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif