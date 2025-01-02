#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {
        set<int> possible_positions;
        possible_positions.insert(x - 1); // Adjusting to 0-based index

        for (auto &throw_info : a) {
            int distance = throw_info.first;
            char direction = throw_info.second;

            if (direction == '?') {
                set<int> new_positions;
                for (int pos : possible_positions) {
                    new_positions.insert((pos + distance) % n);
                    new_positions.insert((pos + n - distance) % n);
                }
                possible_positions = new_positions;
            } else {
                set<int> new_positions;
                for (int pos : possible_positions) {
                    if (direction == '0') {
                        new_positions.insert((pos + distance) % n);
                    } else {
                        new_positions.insert((pos + n - distance) % n);
                    }
                }
                possible_positions = new_positions;
            }
        }

        return possible_positions.size();
    }
};


#endif