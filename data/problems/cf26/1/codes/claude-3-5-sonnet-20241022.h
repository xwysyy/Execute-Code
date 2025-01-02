#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        // For each friend, check if they can always be at least 2 steps away from Vika
        for (auto &friend_pos : a) {
            // If initial Manhattan distance is 1, friend will catch Vika in next move
            int dx = abs(friend_pos.first - x);
            int dy = abs(friend_pos.second - y);
            
            // If friend is at same position or adjacent, Vika can't escape
            if (dx + dy <= 1) {
                return "NO";
            }
        }
        
        // If mall is too small (1x1 or 1x2 or 2x1), Vika can't maintain distance
        if ((n == 1 && m <= 2) || (m == 1 && n <= 2)) {
            return "NO";
        }
        
        // In all other cases, Vika can escape by maintaining distance
        return "YES";
    }
};


#endif