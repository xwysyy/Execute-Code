#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) {
        // For 1x1 grid, we need to rebuild the only city
        if (n == 1 && m == 1) return 1;
        
        // For 1xm or nx1 grid, we need to rebuild all cities
        // as they can't have both horizontal and vertical neighbors
        if (n == 1 || m == 1) return n * m;
        
        // For any other grid size, we need ceil(n/2) * ceil(m/2)
        // This creates a checkerboard pattern which ensures each non-rebuilt
        // city has both horizontal and vertical rebuilt neighbors
        return ((n + 1) / 2) * ((m + 1) / 2);
    }
};


#endif