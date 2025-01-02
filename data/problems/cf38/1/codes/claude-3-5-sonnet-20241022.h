#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {
        // Use set to track possible positions after each throw
        vector<bool> possible(n + 1, false);
        possible[x] = true;
        
        // Process each throw
        for (int i = 0; i < m; i++) {
            vector<bool> next(n + 1, false);
            int dist = a[i].first;
            char dir = a[i].second;
            
            // For each current possible position
            for (int pos = 1; pos <= n; pos++) {
                if (!possible[pos]) continue;
                
                // Calculate next positions based on direction
                if (dir == '?' || dir == '0') {  // Clockwise possible
                    int next_pos = pos + dist;
                    if (next_pos > n) next_pos -= n;
                    next[next_pos] = true;
                }
                
                if (dir == '?' || dir == '1') {  // Counter-clockwise possible
                    int next_pos = pos - dist;
                    if (next_pos <= 0) next_pos += n;
                    next[next_pos] = true;
                }
            }
            
            possible = next;
        }
        
        // Count number of possible final positions
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (possible[i]) count++;
        }
        
        return count;
    }
};


#endif