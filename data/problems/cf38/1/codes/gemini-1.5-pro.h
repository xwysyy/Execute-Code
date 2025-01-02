#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {
        set<int> possible_players;
        function<void(int, int)> dfs = [&](int current_player, int throw_index) {
            if (throw_index == m) {
                possible_players.insert(current_player);
                return;
            }
            int distance = a[throw_index].first;
            char direction = a[throw_index].second;
            if (direction == '0' || direction == '?') {
                int next_player = (current_player + distance - 1) % n + 1;
                dfs(next_player, throw_index + 1);
            }
            if (direction == '1' || direction == '?') {
                int next_player = (current_player - distance - 1 + n) % n + 1;
                dfs(next_player, throw_index + 1);
            }
        };
        dfs(x, 0);
        return possible_players.size();
    }
};


#endif