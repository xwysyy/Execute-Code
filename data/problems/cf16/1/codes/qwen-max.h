#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        int x = abs(a), y = abs(b);
        if (x < y) swap(x, y);
        if (x == 0 && y == 0) return 0;
        
        // If the king can reach the target in a straight line without needing to skip
        if (x + y <= 3) return x + y;
        
        // Calculate the minimum number of moves required
        int min_moves = 2 * (x - 1) + 2;
        if (y > 0) min_moves += 2 * (y - 1) + 1;
        
        return min_moves;
    }
};


#endif