#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {
        if (n == 1) return "YES";  // Base case: single vertex
        
        // Try different values of k from 2 to sqrt(n)
        for (int k = 2; k * k <= n; k++) {
            int vertices = 1;  // Start with one vertex
            int curr = k;     // Current level contribution
            
            // Keep adding vertices level by level
            while (vertices < n) {
                vertices += curr;
                if (vertices == n) return "YES";
                curr *= k;
                
                // Break if we exceed n or overflow
                if (curr > n || vertices > n) break;
            }
        }
        
        return "NO";
    }
};


#endif