#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) != 1) continue;
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                bool can_escape = true;
                for (int i = 0; i < k; i++) {
                    bool can_catch = false;
                    for (int dx2 = -1; dx2 <= 1; dx2++) {
                        for (int dy2 = -1; dy2 <= 1; dy2++) {
                            if (abs(dx2) + abs(dy2) != 1) continue;
                            int nx2 = a[i].first + dx2;
                            int ny2 = a[i].second + dy2;
                            if (nx2 < 1 || nx2 > n || ny2 < 1 || ny2 > m) continue;
                            if (nx2 == nx && ny2 == ny) {
                                can_catch = true;
                                break;
                            }
                        }
                        if (can_catch) break;
                    }
                    if (!can_catch) {
                        can_escape = false;
                        break;
                    }
                }
                if (!can_escape) return "YES";
            }
        }
        return "NO";
    }
};


#endif