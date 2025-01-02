#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        int dx = abs(a);
        int dy = abs(b);
        
        // Maximum distance covered either horizontally or vertically.
        int maxMove = max(dx, dy);
        // The minimum seconds required
        // If dx and dy are different, we will need an extra move
        if (dx != dy) {
            return maxMove + 1; // because of the skip move needed
        } else {
            return maxMove; // both can be covered equally without an extra skip
        }
    }
};


#endif