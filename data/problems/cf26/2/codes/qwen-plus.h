#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {   
        // If Vika is at the edge of the mall, she can be caught by friends moving towards her.
        if (x == 1 || x == n || y == 1 || y == m) {
            return "NO";
        }
        
        // Check if any friend is initially in a neighboring room of Vika.
        for (auto &[fx, fy] : a) {
            if (abs(x - fx) + abs(y - fy) == 1) {
                return "NO";
            }
        }

        // If none of the above conditions are met, Vika can always find a way to avoid her friends.
        return "YES";
    }
};


#endif