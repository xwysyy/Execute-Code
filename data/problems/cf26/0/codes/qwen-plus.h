#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {   
        // Check if Vika starts at a corner or edge
        bool vikaAtCornerOrEdge = (x == 1 || x == n || y == 1 || y == m);
        
        // Check if any friend starts in the same room as Vika
        for (auto &friendPos : a) {
            if (friendPos.first == x && friendPos.second == y) {
                return "NO";
            }
        }
        
        // If Vika is at a corner or edge and all friends are not initially in the same room,
        // she can potentially escape forever by staying on the edge.
        if (vikaAtCornerOrEdge) {
            return "YES";
        }
        
        // If Vika is not at an edge or corner, check if all friends are confined to one parity (odd/even)
        bool allFriendsOdd = true;
        bool allFriendsEven = true;
        int vikaParity = (x + y) % 2;
        
        for (auto &friendPos : a) {
            int friendParity = (friendPos.first + friendPos.second) % 2;
            if (friendParity != 1) allFriendsOdd = false;
            if (friendParity != 0) allFriendsEven = false;
        }
        
        // If Vika's parity is different from all friends' parity, she can always move to avoid them
        if ((allFriendsOdd && vikaParity == 0) || (allFriendsEven && vikaParity == 1)) {
            return "YES";
        }
        
        // In all other cases, Vika cannot escape forever
        return "NO";
    }
};


#endif