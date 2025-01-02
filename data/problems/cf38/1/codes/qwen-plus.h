#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {   
        vector<bool> possible(n, false);
        possible[x-1] = true;

        for (auto &move : a) {
            int dist = move.first;
            char dir = move.second;

            vector<bool> next_possible(n, false);

            for (int i = 0; i < n; ++i) {
                if (!possible[i]) continue;

                if (dir == '0') {
                    // Clockwise throw
                    next_possible[(i + dist) % n] = true;
                } else if (dir == '1') {
                    // Counterclockwise throw
                    next_possible[(i + n - dist) % n] = true;
                } else {
                    // Unknown direction
                    next_possible[(i + dist) % n] = true;
                    next_possible[(i + n - dist) % n] = true;
                }
            }

            possible = next_possible;
        }

        return count(possible.begin(), possible.end(), true);
    }
};


#endif