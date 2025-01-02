#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        // If Vika is not initially in the same room as any of her friends, she can always move to an adjacent room
        // that is not occupied by any of her friends. Since the friends can only move to adjacent rooms and cannot
        // predict Vika's exact move, Vika can always find a way to avoid being caught.
        for (auto &p : a) {
            if (p.first == x && p.second == y) {
                return "NO";
            }
        }
        return "YES";
    }
};

#endif