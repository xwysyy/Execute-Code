#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        // Calculate the parity of Vika's starting position
        int vika_parity = (x + y) % 2;
        
        // Check the parity of each friend's starting position
        bool can_escape = false;
        for (auto &friend_position : a) {
            int x_i = friend_position.first;
            int y_i = friend_position.second;
            int friend_parity = (x_i + y_i) % 2;
            
            // If we find a friend with different parity, escape is possible
            if (friend_parity != vika_parity) {
                can_escape = true;
                break;
            }
        }
        
        // Return "YES" if Vika can escape indefinitely, otherwise "NO"
        return can_escape ? "YES" : "NO";
    }
};


#endif