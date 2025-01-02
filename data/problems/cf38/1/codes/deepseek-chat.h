#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {
        set<int> possiblePositions;
        possiblePositions.insert(x);
        
        for (int i = 0; i < m; ++i) {
            int r = a[i].first;
            char dir = a[i].second;
            set<int> newPositions;
            
            for (int pos : possiblePositions) {
                if (dir == '0') {
                    // Clockwise
                    int newPos = (pos + r - 1) % n + 1;
                    newPositions.insert(newPos);
                } else if (dir == '1') {
                    // Counterclockwise
                    int newPos = (pos - r - 1 + n) % n + 1;
                    newPositions.insert(newPos);
                } else if (dir == '?') {
                    // Both directions
                    int newPosClockwise = (pos + r - 1) % n + 1;
                    int newPosCounterClockwise = (pos - r - 1 + n) % n + 1;
                    newPositions.insert(newPosClockwise);
                    newPositions.insert(newPosCounterClockwise);
                }
            }
            
            possiblePositions = newPositions;
        }
        
        return possiblePositions.size();
    }
};


#endif