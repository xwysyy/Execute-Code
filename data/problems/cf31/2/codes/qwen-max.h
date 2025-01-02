#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) { 
        // If either n or m is 1, then we need to rebuild all cities
        if (n == 1 || m == 1) {
            return n * m;
        }
        
        // For a grid with both dimensions greater than 1, we can use a checkerboard pattern
        // to ensure that every city has at least one horizontally and one vertically neighboring rebuilt city.
        // The minimum number of cities to rebuild is the ceiling of (n * m) / 2.
        return (n * m + 1) / 2;
    }
};

#endif