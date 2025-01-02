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
        
        // Try to assign consistent colors (values) to all elements
        for (int i = 0; i < n; i++) {
            int curr = i;
            int next = (i + 1) % n;
            
            if (s[i] == 'E') {
                // If equal, both elements should have same color
                if (color[next] != -1 && color[next] != color[curr]) 
                    return "NO";
                color[next] = color[curr];
            } else {
                // If not equal, elements should have different colors
                if (color[next] != -1 && color[next] == color[curr]) 
                    return "NO";
                color[next] = color[curr] ^ 1;  // Assign opposite color
            }
        }
        
        // Check if the last relationship is satisfied
        int lastRel = ((color[n-1] == color[0]) ? 'E' : 'N');
        if (lastRel != s[n-1]) 
            return "NO";
            
        return "YES";
    }
};


#endif