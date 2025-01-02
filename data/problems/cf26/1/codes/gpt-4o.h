#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::string solve(int &n, int &m, int &k, int &x, int &y, std::vector<std::pair<int, int>> &a) {
        // Calculate Vika's position parity
        int vika_parity = (x + y) % 2;

        // Check friends' parities
        for (const auto &friend_pos : a) {
            int friend_parity = (friend_pos.first + friend_pos.second) % 2;
            if (friend_parity != vika_parity) {
                return "YES"; // Vika can escape this friend indefinitely
            }
        }
        
        // If all friends have the same parity as Vika, she cannot escape
        return "NO";
    }
};


#endif