#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        // Calculate the parity of Vika's position
        int vika_parity = (x + y) % 2;
        
        // Check the parity of each friend's position
        for (auto &friend_pos : a) {
            int friend_parity = (friend_pos.first + friend_pos.second) % 2;
            // If any friend has the same parity as Vika, she will be caught
            if (friend_parity == vika_parity) {
                return "NO";
            }
        }
        
        // If no friend has the same parity as Vika, she can escape forever
        return "YES";
    }
};


#endif