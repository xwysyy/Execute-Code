#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        int dx = abs(a);
        int dy = abs(b);
        int total = dx + dy;
        if (total == 0) return 0;
        if (dx == dy) {
            return total + (total / 2);
        } else {
            int maxDist = max(dx, dy);
            int minDist = min(dx, dy);
            if (maxDist - minDist <= 1) {
                return total;
            } else {
                return maxDist + (maxDist - 1);
            }
        }
    }
};


#endif