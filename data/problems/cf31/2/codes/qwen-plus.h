#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) { 
        if (n == 1 || m == 1) {
            // If either n or m is 1, we need to rebuild every city since they only have one type of neighbor.
            return max(n, m);
        } else if (n == 2 && m == 2) {
            // For a 2x2 grid, we need to rebuild 2 cities.
            return 2;
        } else {
            // For other cases, we can rebuild cities in a checkerboard pattern starting from (0,0).
            // This ensures that each city will eventually have both a vertical and horizontal rebuilt neighbor.
            return (n * m + 1) / 2;
        }
    }
};


#endif