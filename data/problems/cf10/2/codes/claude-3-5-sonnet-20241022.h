#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, string &s) {
        // Find all positions where current color appears
        vector<int> positions;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                positions.push_back(i);
            }
        }
        
        // Find minimum time to reach green from each position
        int result = n;
        for (int pos : positions) {
            int curr_pos = pos;
            int time = 0;
            // Check each position until we find green
            while (s[curr_pos] != 'g') {
                curr_pos = (curr_pos + 1) % n;
                time++;
            }
            result = min(result, time);
        }
        
        return result;
    }
};


#endif