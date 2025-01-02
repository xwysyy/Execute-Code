#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {   
        // Use a set to track possible positions of the ball.
        set<int> currentPositions;
        currentPositions.insert(x);
        
        for (int i = 0; i < m; ++i) {
            int r = a[i].first;
            char direction = a[i].second;
            
            set<int> newPositions;
            
            // For each current position, calculate new positions for both directions
            for (int pos : currentPositions) {
                
                // Calculate clockwise position
                int clockwisePos = (pos + r - 1) % n + 1;
                // Calculate counterclockwise position
                int counterclockwisePos = (pos - r - 1 + n) % n + 1;
                
                if (direction == '0') {
                    // Known to be clockwise
                    newPositions.insert(clockwisePos);
                } else if (direction == '1') {
                    // Known to be counterclockwise
                    newPositions.insert(counterclockwisePos);
                } else if (direction == '?') {
                    // Unknown: include both directions
                    newPositions.insert(clockwisePos);
                    newPositions.insert(counterclockwisePos);
                }
            }
            
            // Update current possible positions
            currentPositions = newPositions;
        }
        
        // The size of the set is the number of possible players that could have the ball
        return currentPositions.size();
    }
};


#endif