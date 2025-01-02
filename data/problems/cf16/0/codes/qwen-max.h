#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        int dx = abs(a), dy = abs(b);
        if (dx == 0 && dy == 0) return 0;
        
        int max_dist = max(dx, dy);
        int min_dist = min(dx, dy);
        
        // If the maximum distance is even, the king can reach in max_dist + min_dist moves
        if (max_dist % 2 == 0) {
            return max_dist + min_dist;
        } else {
            // If the maximum distance is odd, the king needs one extra move to avoid consecutive same moves
            return max_dist + min_dist + 1;
        }
    }
};

#endif