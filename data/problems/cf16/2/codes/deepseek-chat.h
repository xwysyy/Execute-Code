#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        int dx = abs(a);
        int dy = abs(b);
        int maxDist = max(dx, dy);
        if (dx == dy) {
            return maxDist * 2;
        } else {
            return maxDist * 2 - 1;
        }
    }
};


#endif