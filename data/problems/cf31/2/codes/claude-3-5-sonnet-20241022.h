#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) {
        // Handle 1×1 grid case
        if (n == 1 && m == 1) return 1;
        
        // Handle 1×m or n×1 grid cases
        if (n == 1 || m == 1) return (n * m + 1) / 2;
        
        // For regular grids (n×m where n,m > 1)
        // We need to rebuild cities in a pattern that ensures:
        // 1. Each non-rebuilt city has at least one rebuilt neighbor horizontally
        // 2. Each non-rebuilt city has at least one rebuilt neighbor vertically
        return (n * m + 3) / 4;
    }
};


#endif