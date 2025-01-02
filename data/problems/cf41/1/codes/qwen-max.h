#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {  
        vector<int> winners(q);
        for (int i = 0; i < q; ++i) {
            int players = n[i];
            vector<bool> inGame(players, true);
            while (true) {
                bool kickedOut = false;
                for (int j = 0; j < k && a[j] <= players; ++j) {
                    if (inGame[a[j] - 1]) {
                        inGame[a[j] - 1] = false;
                        kickedOut = true;
                    }
                }
                if (!kickedOut) break;
                // Update the game state
                int newPlayers = 0;
                for (int j = 0; j < players; ++j) {
                    if (inGame[j]) {
                        inGame[newPlayers++] = inGame[j];
                    }
                }
                players = newPlayers;
                fill(inGame.begin() + players, inGame.end(), false);
            }
            winners[i] = count(inGame.begin(), inGame.end(), true);
        }
        return winners;
    }
};

#endif