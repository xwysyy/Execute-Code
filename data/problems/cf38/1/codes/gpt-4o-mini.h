#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {   
        // Using a set to record possible players that could have the ball
        set<int> currentPlayers;
        currentPlayers.insert(x); // Start with the initial player who has the ball
        
        // Process each throw one by one
        for (int i = 0; i < m; ++i) {
            char direction = a[i].second;
            int distance = a[i].first;
            set<int> nextPlayers;
            
            // For each current player in the possible set
            for (int player : currentPlayers) {
                if (direction == '0') {
                    // Clockwise
                    nextPlayers.insert((player - 1 + distance) % n + 1); // 1-based
                } else if (direction == '1') {
                    // Counterclockwise
                    nextPlayers.insert((player - 1 - distance + n) % n + 1); // 1-based
                } else { // direction == '?'
                    // Both possibilities
                    nextPlayers.insert((player - 1 + distance) % n + 1); // Clockwise
                    nextPlayers.insert((player - 1 - distance + n) % n + 1); // Counterclockwise
                }
            }
            // Update current possible players
            currentPlayers = nextPlayers;
        }

        // The size of the set is the number of distinct players who could have the ball
        return currentPlayers.size();
    }
};


#endif