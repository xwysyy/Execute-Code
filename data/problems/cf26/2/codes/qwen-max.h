#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        // If Vika is at the corner and there is only one friend, she can always escape.
        if ((x == 1 || x == n) && (y == 1 || y == m) && k == 1) return "YES";
        
        // If Vika is not at the corner, she can always move to a corner.
        if (x != 1 && x != n && y != 1 && y != m) return "YES";
        
        // Check if any friend is in a position to block Vika from moving to a corner.
        for (auto &p : a) {
            if (p.first == x && p.second == y) return "NO"; // Friend is in the same room as Vika.
            if (abs(p.first - x) + abs(p.second - y) == 1) {
                // Friend is in a neighboring room.
                if (x == 1 || x == n || y == 1 || y == m) return "NO"; // Vika is already at the edge and cannot move to a corner.
            }
        }
        
        // If none of the friends can block Vika, she can always move to a corner.
        return "YES";
    }
};


#endif