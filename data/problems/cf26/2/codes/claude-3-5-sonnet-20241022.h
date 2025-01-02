#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        // For each friend, check if they can maintain distance <= 1 from Vika
        for (auto &friend_pos : a) {
            // If any friend starts at the same position as Vika
            // They can always follow her moves and catch her
            if (friend_pos.first == x && friend_pos.second == y) {
                return "NO";
            }
            
            // If any friend starts adjacent to Vika
            // They can catch her in their next move
            if (abs(friend_pos.first - x) + abs(friend_pos.second - y) == 1) {
                return "NO";
            }
        }
        
        // If Vika starts with distance >= 2 from all friends,
        // she can always maintain this distance by moving away
        return "YES";
    }
};


#endif