#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        // Calculate direct move counts in x and y directions
        int x = abs(a);
        int y = abs(b);
        
        // For the king to move, we need to reach both coordinates, alternating the moves.
        // Now, with those conditions, the minimum required moves is determined
        // by the maximum of x, y. This is because we will alternate the moves in a sequence
        // like (x, y, x, y...) or (y, x, y, x...).

        // The minimum moves needed would be max(x, y) + the resting moves due to alternating.
        // If either x or y is odd, it naturally fits the alternating pattern, otherwise we need 
        // to stop at least once extra if both are even because the move pattern becomes different.
        
        // Calculate the number of resting moves between a full cycle.
        int rest_moves = (x != y) ? 0 : (x % 2 == 0 ? 1 : 0);

        // Calculate total minimum moves
        return max(x, y) * 2 + rest_moves;
    }
};


#endif