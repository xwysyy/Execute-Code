#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) {
        if (n == 1 || m == 1) {
            // If either n or m is 1, we need to rebuild every city because they only have one type of neighbor.
            return max(n, m);
        } else if (n == 2 || m == 2) {
            // If either n or m is 2, we can rebuild cities in a checkerboard pattern.
            // This ensures that all cities will eventually be rebuilt.
            return (n * m + 1) / 2;
        } else {
            // For larger grids, we can rebuild every other city in a checkerboard pattern.
            // This ensures that each collapsed city has at least one vertical and one horizontal rebuilt neighbor.
            return (n * m + 1) / 2;
        }
    }
};


#endif