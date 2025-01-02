#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {
        if (n == 1) return "NO";  // Can't form snowflake with 1 vertex as k > 1
        if (n == 2) return "NO";  // Can't form snowflake with 2 vertices as k > 1
        
        // For any k > 1, a snowflake can have vertices in the form:
        // 1 + k + k*k + ... where k > 1
        // This means n-1 should be divisible by some number > 1
        
        // Check if n-1 has any divisors greater than 1
        for (int i = 2; i * i <= n-1; i++) {
            if ((n-1) % i == 0) return "YES";
        }
        
        // Also check if n-1 itself is greater than 1
        if (n-1 > 1) return "YES";
        
        return "NO";
    }
};


#endif