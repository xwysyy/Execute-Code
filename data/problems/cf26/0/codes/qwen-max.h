#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        // If Vika is at the edge of the grid, she can always escape
        if (x == 1 || x == n || y == 1 || y == m) {
            return "YES";
        }
        
        // Check if any friend is already in the same room as Vika
        for (auto &p : a) {
            if (p.first == x && p.second == y) {
                return "NO";
            }
        }
        
        // Check if Vika can move to a position where no friend can catch her
        bool canEscape = true;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (abs(dx) + abs(dy) == 1) {
                    int nx = x + dx;
                    int ny = y + dy;
                    bool safe = true;
                    for (auto &p : a) {
                        int fx = p.first;
                        int fy = p.second;
                        if ((fx + 1 == nx && fy == ny) || (fx - 1 == nx && fy == ny) ||
                            (fy + 1 == ny && fx == nx) || (fy - 1 == ny && fx == nx)) {
                            safe = false;
                            break;
                        }
                    }
                    if (safe) {
                        return "YES";
                    }
                }
            }
        }
        
        return "NO";
    }
};

#endif