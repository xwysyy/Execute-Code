#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {
        // Initialize set with the starting position
        set<int> possible_positions;
        possible_positions.insert(x);

        // Process each throw
        for (const auto& throw_info : a) {
            int distance = throw_info.first;
            char direction = throw_info.second;
            set<int> new_positions;

            // Calculate potential new positions based on current possible positions
            for (int current_position : possible_positions) {
                current_position = (current_position - 1) % n; // Convert to zero-indexed

                if (direction == '0' || direction == '?') {
                    // Clockwise position
                    new_positions.insert((current_position + distance) % n);
                }
                if (direction == '1' || direction == '?') {
                    // Counterclockwise position
                    new_positions.insert((current_position - distance + n) % n);
                }
            }

            // Update possible positions for next iteration
            possible_positions = new_positions;
        }

        // The result is the size of the possible positions set
        return possible_positions.size();
    }
};


#endif