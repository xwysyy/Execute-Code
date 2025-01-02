#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {
        // Initialize a set to keep track of possible positions
        set<int> possiblePositions;
        possiblePositions.insert(x);

        // Iterate through each throw
        for (int i = 0; i < m; ++i) {
            int distance = a[i].first;
            char direction = a[i].second;
            set<int> newPossiblePositions;

            // For each possible position, calculate the new positions based on the throw
            for (int pos : possiblePositions) {
                if (direction == '0') {
                    // Clockwise throw
                    int newPos = (pos + distance - 1) % n + 1;
                    newPossiblePositions.insert(newPos);
                } else if (direction == '1') {
                    // Counterclockwise throw
                    int newPos = (pos - distance - 1 + n) % n + 1;
                    newPossiblePositions.insert(newPos);
                } else if (direction == '?') {
                    // Unknown direction, consider both possibilities
                    int newPosClockwise = (pos + distance - 1) % n + 1;
                    int newPosCounterclockwise = (pos - distance - 1 + n) % n + 1;
                    newPossiblePositions.insert(newPosClockwise);
                    newPossiblePositions.insert(newPosCounterclockwise);
                }
            }

            // Update the possible positions
            possiblePositions = newPossiblePositions;
        }

        // Return the number of possible positions
        return possiblePositions.size();
    }
};


#endif