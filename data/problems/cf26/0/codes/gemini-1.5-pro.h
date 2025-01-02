#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (abs(dx) + abs(dy) != 1) continue;
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                bool caught = false;
                for (int i = 0; i < k; ++i) {
                    if (abs(a[i].first - nx) + abs(a[i].second - ny) <= 1) {
                        caught = true;
                        break;
                    }
                }
                if (!caught) return "YES";
            }
        }
        return "NO";
    }
};


#endif