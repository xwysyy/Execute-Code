#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {   
        vector<bool> possible(n, true);
        int initial_pos = x - 1; // Convert to 0-based index
        
        for (int i = 0; i < m; ++i) {
            vector<bool> new_possible(n, false);
            int dist = a[i].first;
            char direction = a[i].second;
            
            for (int j = 0; j < n; ++j) {
                if (!possible[j]) continue;
                
                if (direction == '0') {
                    // Clockwise throw
                    int new_pos = (j + dist) % n;
                    new_possible[new_pos] = true;
                } else if (direction == '1') {
                    // Counterclockwise throw
                    int new_pos = (j - dist + n) % n;
                    new_possible[new_pos] = true;
                } else {
                    // Unknown direction
                    int new_pos_clockwise = (j + dist) % n;
                    int new_pos_counterclockwise = (j - dist + n) % n;
                    new_possible[new_pos_clockwise] = true;
                    new_possible[new_pos_counterclockwise] = true;
                }
            }
            possible = new_possible;
        }
        
        return count(possible.begin(), possible.end(), true);
    }
};


#endif