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

        for (int i = 0; i < m; ++i) {
            int distance = a[i].first;
            char direction = a[i].second;
            set<int> newPossiblePositions;

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
                    // Unknown direction, consider both
                    int newPosClockwise = (pos + distance - 1) % n + 1;
                    int newPosCounterClockwise = (pos - distance - 1 + n) % n + 1;
                    newPossiblePositions.insert(newPosClockwise);
                    newPossiblePositions.insert(newPosCounterClockwise);
                }
            }

            possiblePositions = newPossiblePositions;
        }

        return possiblePositions.size();
    }
};


#endif