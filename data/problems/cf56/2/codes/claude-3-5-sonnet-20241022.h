#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, std::string &s) {
        int timar_count = 0;
        int current_weak = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                current_weak++;
            } else {
                current_weak = 0; // Reset as we encountered a '1'
            }

            // If we reach m weak spots, use Timar
            if (current_weak == m) {
                timar_count++;
                // Strengthen by applying Timar
                int change_length = std::min(k, n - i);
                for (int j = 0; j < change_length; ++j) {
                    s[i + j] = '1';
                }
                // Reset current_weak
                current_weak = 0;
            }
        }
        
        return timar_count;
    }
};


#endif