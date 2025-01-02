#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        vector<bool> coins(n);  // true for up, false for down
        
        // Convert string to boolean array
        for (int i = 0; i < n; i++) {
            coins[i] = (s[i] == 'U');
        }
        
        // Count initial number of up-facing coins
        int upCount = count(coins.begin(), coins.end(), true);
        
        // If no up-facing coins initially, Alice loses immediately
        if (upCount == 0) {
            return "NO";
        }
        
        // Key observation: In each turn, the number of up-facing coins
        // decreases by 1 or increases by 1 (or stays same in special cases)
        // The player who makes the last move wins
        // If initial count is odd, Alice wins; if even, Bob wins
        return (upCount % 2 == 1) ? "YES" : "NO";
    }
};


#endif