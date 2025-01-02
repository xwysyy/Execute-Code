#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        int dist = max(abs(a), abs(b));
        if (dist == 0) return 0; // If the target is the starting position
        
        // The king can move in a zigzag pattern to reach the target
        // The minimum time is 2 * (distance - 1) + 1
        // This is because the king can move in a pattern like: up, right, down, right, ...
        // This ensures that no two consecutive moves are the same
        return 2 * (dist - 1) + 1;
    }
};


#endif