#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to check if there are any up-facing coins
    bool hasUpCoins(const string& s) {
        for (char c : s) {
            if (c == 'U') return true;
        }
        return false;
    }
    
    // Helper function to make a move and get new state
    string makeMove(string s, int pos) {
        int n = s.length();
        s[pos] = 'D';  // Remove the up-facing coin
        
        // If more than 2 coins, flip adjacent coins
        if (n > 2) {
            s[(pos + 1) % n] = (s[(pos + 1) % n] == 'U') ? 'D' : 'U';
            s[(pos - 1 + n) % n] = (s[(pos - 1 + n) % n] == 'U') ? 'D' : 'U';
        }
        // If exactly 2 coins, no flipping needed (as it would flip twice)
        
        return s;
    }
    
    // Helper function to check if current player can win from this position
    bool canWin(string s) {
        // Base case: if no up-facing coins, current player loses
        if (!hasUpCoins(s)) return false;
        
        int n = s.length();
        // Try each possible move
        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') {
                // Make move and check if opponent loses
                string newState = makeMove(s, i);
                if (!canWin(newState)) return true;
            }
        }
        return false;
    }
    
public:
    string solve(int &n, string &s) {
        // Check if Alice can win with optimal play
        return canWin(s) ? "YES" : "NO";
    }
};


#endif