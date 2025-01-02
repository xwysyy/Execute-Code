#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        // For each friend, check if they can always be at least 2 steps away from Vika
        for (auto &friend_pos : a) {
            // Calculate Manhattan distance between Vika and current friend
            int dist = abs(x - friend_pos.first) + abs(y - friend_pos.second);
            
            // If any friend is too close (distance < 2), they can catch Vika
            // Because after Vika moves, the friend can move to the same position
            if (dist < 2) {
                return "NO";
            }
        }
        
        // If the mall is too small (1x1 or 1x2 or 2x1), Vika can't escape
        if ((n == 1 && m <= 2) || (m == 1 && n <= 2)) {
            return "NO";
        }
        
        // If we reach here, Vika can maintain distance by moving away from friends
        return "YES";
    }
};


#endif