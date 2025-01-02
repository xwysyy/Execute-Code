#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        for (auto &friend_pos : a) {
            int fx = friend_pos.first;
            int fy = friend_pos.second;
            // Check if the friend is adjacent to Vika
            if ((abs(fx - x) + abs(fy - y)) == 1) {
                return "NO";
            }
        }
        return "YES";
    }
};


#endif