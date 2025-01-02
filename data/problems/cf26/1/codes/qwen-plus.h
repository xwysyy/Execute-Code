#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {   
        // If Vika is at the edge of the mall, she can be caught by her friends.
        if (x == 1 || x == n || y == 1 || y == m) {
            return "NO";
        }
        
        // Check if any friend starts in a position that can catch Vika immediately.
        for (auto &friendPos : a) {
            int fx = friendPos.first;
            int fy = friendPos.second;
            if ((abs(x - fx) + abs(y - fy)) <= 1) {
                return "NO";
            }
        }
        
        // If none of the friends are adjacent to Vika and Vika is not at the edge,
        // she can always move to avoid being caught.
        return "YES";
    }
};


#endif