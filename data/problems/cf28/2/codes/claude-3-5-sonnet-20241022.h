#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        int n = a.length();
        
        // Check if strings can be made equal
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                // Find next matching position
                int j = i + 1;
                while (j < n && a[j] != a[i]) j++;
                
                // If no matching position found, check if b can be transformed
                if (j == n) {
                    j = i + 1;
                    while (j < n && b[j] != b[i]) j++;
                    if (j == n) return "NO";
                }
                
                // Transform the substring in both strings
                for (int k = i + 1; k < j; k++) {
                    a[k] = a[i];
                    b[k] = b[i];
                }
            }
        }
        
        return "YES";
    }
};


#endif