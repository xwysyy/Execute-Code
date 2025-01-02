#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        // If the target is the starting position, no moves are needed.
        if (a == 0 && b == 0) return 0;

        // Calculate the absolute distance in both dimensions.
        int dist_a = abs(a);
        int dist_b = abs(b);

        // The maximum of these distances gives the minimum number of moves required
        // without considering the restriction on consecutive moves.
        int max_dist = max(dist_a, dist_b);

        // If the sum of distances is odd, an extra move is needed because
        // the king cannot make two consecutive moves in the same direction.
        if ((dist_a + dist_b) % 2 != 0) {
            return max_dist + 1;
        } else {
            return max_dist;
        }
    }
};


#endif