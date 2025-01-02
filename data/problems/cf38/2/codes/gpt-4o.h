#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, std::vector<std::pair<int, char>> &a) {
        // Initialize the set of possible positions with the starting position
        std::unordered_set<int> possible_positions;
        possible_positions.insert(x);

        // Iterate through each move
        for (const auto &move : a) {
            int distance = move.first;
            char direction = move.second;

            // Prepare a new set to store the result of this move
            std::unordered_set<int> new_positions;

            for (int pos : possible_positions) {
                // Compute possible positions for each current position
                if (direction == '0' || direction == '?') {
                    // Clockwise move
                    int new_pos = (pos + distance - 1) % n + 1;
                    new_positions.insert(new_pos);
                }
                if (direction == '1' || direction == '?') {
                    // Counterclockwise move
                    int new_pos = (pos - distance - 1 + n) % n + 1;
                    new_positions.insert(new_pos);
                }
            }

            // Update the possible positions set
            possible_positions = std::move(new_positions);
        }

        // Return the number of possible final positions
        return possible_positions.size();
    }
};


#endif