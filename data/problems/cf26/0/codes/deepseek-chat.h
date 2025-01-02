#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        // Vika's initial position parity
        int vika_parity = (x + y) % 2;

        // Check if any friend has the same parity as Vika
        for (auto &friend_pos : a) {
            int friend_parity = (friend_pos.first + friend_pos.second) % 2;
            if (friend_parity == vika_parity) {
                return "NO";
            }
        }

        return "YES";
    }
};


#endif