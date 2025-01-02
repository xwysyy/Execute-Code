#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &a, int &b) {
        int max_moves = max(abs(a), abs(b));
        int min_moves = min(abs(a), abs(b));
        int diff = max_moves - min_moves;

        if (diff == 0) {
            return max_moves;
        } else {
            return min_moves * 2 + (diff % 2 == 0 ? diff : diff + 1);
        }
    }
};


#endif