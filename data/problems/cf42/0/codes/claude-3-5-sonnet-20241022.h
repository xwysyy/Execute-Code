#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        // Convert string to vector for easier manipulation
        vector<int> coins(n);
        for(int i = 0; i < n; i++) {
            coins[i] = (s[i] == 'U') ? 1 : 0;
        }
        
        // If Alice can win with optimal play
        return canWin(coins, true) ? "YES" : "NO";
    }
    
private:
    bool canWin(vector<int>& coins, bool isAlice) {
        // Count facing up coins
        int upCount = 0;
        for(int coin : coins) {
            if(coin == 1) upCount++;
        }
        
        // If no coins are facing up, current player loses
        if(upCount == 0) return !isAlice;
        
        // Try each possible move
        for(int i = 0; i < coins.size(); i++) {
            if(coins[i] == 1) {  // If coin is facing up
                vector<int> nextState = coins;
                nextState[i] = 0;  // Remove this coin
                
                // Flip adjacent coins if they exist
                if(coins.size() > 2) {
                    int prev = (i - 1 + coins.size()) % coins.size();
                    int next = (i + 1) % coins.size();
                    nextState[prev] ^= 1;
                    nextState[next] ^= 1;
                }
                else if(coins.size() == 2) {
                    // For 2 coins, only remove one, don't flip the other
                    nextState.erase(nextState.begin() + i);
                }
                else {
                    // For 1 coin, just remove it
                    nextState.clear();
                }
                
                // If this move leads to a win
                if(!canWin(nextState, !isAlice)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};


#endif