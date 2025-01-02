#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {
        // Initialize a set with the starting player position
        set<int> current_positions;
        current_positions.insert(x);

        for (int i = 0; i < m; ++i) {
            int distance = a[i].first;
            char direction = a[i].second;

            set<int> new_positions;

            for (int position : current_positions) {
                if (direction == '0') {
                    // Clockwise move
                    int new_position = (position + distance - 1) % n + 1;
                    new_positions.insert(new_position);
                } else if (direction == '1') {
                    // Counterclockwise move
                    int new_position = ((position - distance - 1 + n) % n) + 1;
                    new_positions.insert(new_position);
                } else if (direction == '?') {
                    // Handle both directions
                    // Clockwise possible move
                    int new_position_clockwise = (position + distance - 1) % n + 1;
                    new_positions.insert(new_position_clockwise);

                    // Counterclockwise possible move
                    int new_position_counterclockwise = ((position - distance - 1 + n) % n) + 1;
                    new_positions.insert(new_position_counterclockwise);
                }
            }

            // Update current positions to new calculated positions
            current_positions = move(new_positions);
        }

        // Return the number of distinct players who could have the ball
        return current_positions.size();
    }
};


#endif