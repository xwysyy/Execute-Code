#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        int verticalDistance = abs(a);
        int horizontalDistance = abs(b);
        
        if (verticalDistance > 0 && horizontalDistance > 0) {
            // Both directions to move
            return max(verticalDistance, horizontalDistance);
        } else {
            // One direction is zero
            return max(verticalDistance, horizontalDistance) + 1;
        }
    }
};


#endif