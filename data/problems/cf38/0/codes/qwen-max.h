#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {
        set<int> possible_positions;
        possible_positions.insert(x - 1); // Adjusting to 0-based index

        for (int i = 0; i < m; ++i) {
            int distance = a[i].first;
            char direction = a[i].second;
            set<int> new_positions;

            for (int pos : possible_positions) {
                if (direction == '0' || direction == '?') {
                    // Clockwise
                    int new_pos = (pos + distance) % n;
                    new_positions.insert(new_pos);
                }
                if (direction == '1' || direction == '?') {
                    // Counterclockwise
                    int new_pos = (pos - distance + n) % n;
                    new_positions.insert(new_pos);
                }
            }

            possible_positions = move(new_positions);
        }

        return possible_positions.size();
    }
};


#endif