#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Create a dp array to store reachable positions
        vector<vector<bool>> dp(2, vector<bool>(n, false));
        
        // Check if starting position is safe
        if (s1[0] == '1') return "NO";
        dp[0][0] = true;
        
        // Fill dp array
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < 2; i++) {
                if (!dp[i][j]) continue;
                
                // Try all possible moves from current position
                for (int newRow = max(0, i-1); newRow <= min(1, i+1); newRow++) {
                    for (int newCol = j+1; newCol <= min(n-1, j+1); newCol++) {
                        // Check if target cell is safe
                        if ((newRow == 0 && s1[newCol] == '0') || 
                            (newRow == 1 && s2[newCol] == '0')) {
                            dp[newRow][newCol] = true;
                        }
                    }
                }
            }
        }
        
        // Check if target cell is reachable
        return dp[1][n-1] ? "YES" : "NO";
    }
};


#endif