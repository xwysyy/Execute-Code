#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {
        if (n == 1) return "NO";  // Can't be 1 as k must be > 1
        
        // Try different values of k from 2 to sqrt(n)
        for (int k = 2; k * k <= n; k++) {
            int vertices = 1;
            int power = 1;
            
            // Calculate sum of geometric progression
            while (vertices < n) {
                vertices += power * k;
                power *= k;
            }
            
            if (vertices == n) return "YES";
        }
        
        return "NO";
    }
};


#endif