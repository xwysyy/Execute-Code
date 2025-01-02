#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {
        set<int> possible_players;
        function<void(int, int)> recurse = 
            [&](int current_player, int throw_index) {
            if (throw_index == m) {
                possible_players.insert(current_player);
                return;
            }

            if (a[throw_index].second == '?') {
                int next_player_cw = (current_player + a[throw_index].first - 1) % n + 1;
                recurse(next_player_cw, throw_index + 1);
                int next_player_ccw = (current_player - a[throw_index].first - 1 + n) % n + 1;
                recurse(next_player_ccw, throw_index + 1);
            } else if (a[throw_index].second == '0') {
                int next_player_cw = (current_player + a[throw_index].first - 1) % n + 1;
                recurse(next_player_cw, throw_index + 1);
            } else {
                int next_player_ccw = (current_player - a[throw_index].first - 1 + n) % n + 1;
                recurse(next_player_ccw, throw_index + 1);
            }
        };

        recurse(x, 0);
        return possible_players.size();
    }
};


#endif