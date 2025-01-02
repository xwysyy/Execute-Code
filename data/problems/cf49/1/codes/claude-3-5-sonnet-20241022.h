#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        // If length is odd, we must delete one character
        if (n % 2 == 1) {
            int minOps = n;
            // Try deleting each character and check the resulting even-length string
            for (int i = 0; i < n; i++) {
                string temp = s.substr(0, i) + s.substr(i + 1);
                // Calculate minimum operations needed for the resulting string
                minOps = min(minOps, getMinOpsForEvenString(temp));
            }
            return minOps + 1; // Add 1 for the deletion operation
        }
        
        // If length is even, just calculate minimum operations needed
        return getMinOpsForEvenString(s);
    }
    
private:
    int getMinOpsForEvenString(const string& s) {
        int n = s.length();
        if (n == 0) return 0;
        
        // Try all possible pairs of letters for even and odd positions
        int minOps = n;
        for (char c1 = 'a'; c1 <= 'z'; c1++) {
            for (char c2 = 'a'; c2 <= 'z'; c2++) {
                int ops = 0;
                // Count changes needed to make even positions c1 and odd positions c2
                for (int i = 0; i < n; i++) {
                    if (i % 2 == 0 && s[i] != c1) ops++;
                    if (i % 2 == 1 && s[i] != c2) ops++;
                }
                minOps = min(minOps, ops);
            }
        }
        return minOps;
    }
};


#endif