#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        // If string length is 1, we need 1 deletion
        if (n == 1) return 1;
        
        int minOps = n; // Initialize with worst case
        
        // Try without deletion
        minOps = min(minOps, getMinChanges(s));
        
        // Try with deletion (try removing each character)
        for (int i = 0; i < n; i++) {
            string temp = s.substr(0, i) + s.substr(i + 1);
            if (temp.length() % 2 == 0) { // Only consider if resulting length is even
                minOps = min(minOps, 1 + getMinChanges(temp));
            }
        }
        
        return minOps;
    }
    
private:
    // Helper function to count minimum changes needed for an even-length string
    int getMinChanges(const string& s) {
        if (s.length() % 2 != 0) return s.length(); // Invalid case
        
        int n = s.length();
        if (n == 0) return 0;
        
        // Try all possible pairs of letters for even and odd positions
        int minChanges = n;
        for (char c1 = 'a'; c1 <= 'z'; c1++) {
            for (char c2 = 'a'; c2 <= 'z'; c2++) {
                int changes = 0;
                for (int i = 0; i < n; i++) {
                    if (i % 2 == 0 && s[i] != c1) changes++;
                    if (i % 2 == 1 && s[i] != c2) changes++;
                }
                minChanges = min(minChanges, changes);
            }
        }
        return minChanges;
    }
};


#endif