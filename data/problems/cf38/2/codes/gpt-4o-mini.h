#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {
        // Use a set to store reachable positions
        set<int> reachable;
        // Start tracking from the initial player
        reachable.insert(x);
        
        // Process each throw
        for (const auto &throw_info : a) {
            int distance = throw_info.first;
            char direction = throw_info.second;
            set<int> new_reachable;
            
            // Iterate through current reachable positions
            for (int player : reachable) {
                if (direction == '0') {  // Clockwise
                    int next_player = (player - 1 + distance) % n + 1;
                    new_reachable.insert(next_player);
                } else if (direction == '1') {  // Counterclockwise
                    int next_player = (player - 1 - distance + n) % n + 1;
                    new_reachable.insert(next_player);
                } else {  // direction == '?'
                    // Clockwise option
                    int next_player_clockwise = (player - 1 + distance) % n + 1;
                    new_reachable.insert(next_player_clockwise);
                    // Counterclockwise option
                    int next_player_counterclockwise = (player - 1 - distance + n) % n + 1;
                    new_reachable.insert(next_player_counterclockwise);
                }
            }
            // Update the reachable set for the next step
            reachable = new_reachable;
        }
        
        return reachable.size();  // The number of distinct players who could have the ball
    }
};


#endif