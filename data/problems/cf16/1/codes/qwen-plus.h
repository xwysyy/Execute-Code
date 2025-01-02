#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        // If the target is the starting position, no moves are needed.
        if (a == 0 && b == 0) return 0;

        // Calculate the Manhattan distance from (0, 0) to (a, b).
        int distance = abs(a) + abs(b);

        // The minimum number of moves required if the king could move freely.
        int minMoves = max(abs(a), abs(b));

        // Adjust for the constraint that the same move cannot be made consecutively.
        // If the distance is even, we can reach the target in exactly minMoves.
        // If the distance is odd, we need one extra move (either a skip or an extra move in some direction).
        if (distance % 2 == 0) {
            return minMoves;
        } else {
            return minMoves + 1;
        }
    }
};


#endif