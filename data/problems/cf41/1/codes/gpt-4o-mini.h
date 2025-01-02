#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {
        vector<int> result;
        
        for (int players : n) {
            // We will keep track of players in the game
            vector<bool> isInGame(players + 1, true); // Players are indexed from 1 to players
            
            while (true) {
                bool anyKicked = false;
                
                for (int index : a) {
                    if (index <= players && isInGame[index]) { // Ensure index is within bounds
                        isInGame[index] = false; // Kick the player out
                        anyKicked = true; // Mark that we kicked someone out
                    }
                }
                
                // If no one was kicked out in this round, we can break
                if (!anyKicked) {
                    break;
                }
                
                // Update the players count after kicks
                int newPlayersCount = 0;
                for (int i = 1; i <= players; ++i) {
                    if (isInGame[i]) {
                        newPlayersCount++; // Count remaining players
                    }
                }
                players = newPlayersCount; // Update players count for the next round
            }
            
            // Count the remaining players who are still in
            int winners = 0;
            for (int i = 1; i <= players; ++i) {
                if (isInGame[i]) {
                    winners++;
                }
            }
            result.push_back(winners);
        }
        
        return result;
    }
};


#endif