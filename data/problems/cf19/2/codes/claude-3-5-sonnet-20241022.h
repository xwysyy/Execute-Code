#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {
        int n = s.length();
        vector<vector<int>> table(n, vector<int>(n));
        
        // Build the table with cyclic shifts
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Calculate position after cyclic shift
                int pos = (j + i) % n;
                table[i][j] = s[pos] - '0';
            }
        }
        
        // For each possible rectangle
        long long maxArea = 0;
        for (int y1 = 0; y1 < n; y1++) {
            for (int y2 = y1; y2 < n; y2++) {
                // Count consecutive ones for each column in current row range
                vector<int> consecutive(n, 0);
                for (int x = 0; x < n; x++) {
                    bool allOnes = true;
                    for (int y = y1; y <= y2; y++) {
                        if (table[y][x] == 0) {
                            allOnes = false;
                            break;
                        }
                    }
                    if (allOnes) consecutive[x] = 1;
                }
                
                // Find longest sequence of ones in consecutive[]
                int curr = 0;
                for (int x = 0; x < n; x++) {
                    if (consecutive[x]) {
                        curr++;
                        // Update maxArea with current rectangle
                        long long height = y2 - y1 + 1;
                        maxArea = max(maxArea, height * curr);
                    } else {
                        curr = 0;
                    }
                }
            }
        }
        
        return maxArea;
    }
};


#endif