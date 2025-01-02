#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        // For n elements, we need exactly n characters in s
        // Each character represents relationship between adjacent elements
        vector<int> color(n, -1);
        color[0] = 0;  // Start with first element colored as 0
        
        // Try to color the graph with 2 colors (0 and 1)
        // If two adjacent positions have 'E', they should have same color
        // If two adjacent positions have 'N', they should have different colors
        for (int i = 0; i < n; i++) {
            int curr = i;
            int next = (i + 1) % n;
            
            if (color[curr] == -1) continue;
            
            if (s[i] == 'E') {
                // Adjacent elements should be equal
                if (color[next] != -1 && color[next] != color[curr])
                    return "NO";
                color[next] = color[curr];
            } else {
                // Adjacent elements should be different
                if (color[next] != -1 && color[next] == color[curr])
                    return "NO";
                color[next] = 1 - color[curr];
            }
        }
        
        // Check the last connection (between last and first element)
        if ((s[n-1] == 'E' && color[n-1] != color[0]) ||
            (s[n-1] == 'N' && color[n-1] == color[0])) {
            return "NO";
        }
        
        return "YES";
    }
};


#endif