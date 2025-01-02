#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &x, vector<pair<int, char>> &a) {   
        vector<bool> possible(n, true);
        int current = x - 1; // Convert to 0-based index
        
        for (int i = 0; i < m; ++i) {
            if (a[i].second == '0') {
                // Clockwise throw
                current = (current + a[i].first) % n;
                for (int j = 0; j < n; ++j) {
                    if ((current - j + n) % n != (current + a[i].first) % n) {
                        possible[j] = false;
                    }
                }
            } else if (a[i].second == '1') {
                // Counterclockwise throw
                current = (current - a[i].first + n) % n;
                for (int j = 0; j < n; ++j) {
                    if ((current - j + n) % n != (current - a[i].first + n) % n) {
                        possible[j] = false;
                    }
                }
            } else {
                // Unknown direction
                vector<bool> new_possible(n, false);
                for (int j = 0; j < n; ++j) {
                    if (possible[j]) {
                        int clockwise = (j + a[i].first) % n;
                        int counterclockwise = (j - a[i].first + n) % n;
                        new_possible[clockwise] = true;
                        new_possible[counterclockwise] = true;
                    }
                }
                possible = new_possible;
            }
        }

        int count = 0;
        for (bool p : possible) {
            if (p) count++;
        }
        
        return count;
    }
};


#endif