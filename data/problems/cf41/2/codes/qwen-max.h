#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {
        vector<int> result(q);
        for (int i = 0; i < q; ++i) {
            int players = n[i];
            vector<bool> kickedOut(players + 1, false);
            while (true) {
                bool someoneKickedOut = false;
                for (int j = 0; j < k && a[j] <= players; ++j) {
                    if (!kickedOut[a[j]]) {
                        kickedOut[a[j]] = true;
                        someoneKickedOut = true;
                    }
                }
                if (!someoneKickedOut) break;
                
                int newPlayers = 0;
                for (int j = 1; j <= players; ++j) {
                    if (!kickedOut[j]) {
                        kickedOut[++newPlayers] = kickedOut[j];
                    }
                }
                players = newPlayers;
            }
            result[i] = players;
        }
        return result;
    }
};


#endif