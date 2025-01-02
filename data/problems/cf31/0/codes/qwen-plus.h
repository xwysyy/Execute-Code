#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) {
        if (n == 1 || m == 1) {
            // If either n or m is 1, we need to rebuild every city because there are no vertical and horizontal neighbors for all cities.
            return n * m;
        } else if (n == 2 || m == 2) {
            // If either n or m is 2, we can alternate rebuilding cities in a checkerboard pattern.
            // This ensures that each collapsed city will have both a vertical and horizontal rebuilt neighbor.
            return (n * m + 1) / 2;
        } else {
            // For larger grids, we can use a checkerboard pattern starting from (0,0).
            // This pattern ensures that each collapsed city will eventually have both a vertical and horizontal rebuilt neighbor.
            return (n * m + 1) / 2;
        }
    }
};


#endif