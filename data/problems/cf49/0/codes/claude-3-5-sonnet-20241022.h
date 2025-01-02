#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        // If length is 1, we need 1 deletion to make it even length
        if (n == 1) return 1;
        
        // Try both possibilities: keeping all characters or deleting one
        int ans = getMinOperations(s);
        
        // Try removing each character and check
        for (int i = 0; i < n; i++) {
            string temp = s.substr(0, i) + s.substr(i + 1);
            ans = min(ans, getMinOperations(temp) + 1);
        }
        
        return ans;
    }
    
private:
    // Helper function to get minimum operations needed without deletion
    int getMinOperations(const string& s) {
        if (s.length() % 2 == 1) return INT_MAX;
        
        // Try all possible pairs of letters for even and odd positions
        int minOps = INT_MAX;
        for (char c1 = 'a'; c1 <= 'z'; c1++) {
            for (char c2 = 'a'; c2 <= 'z'; c2++) {
                int ops = 0;
                for (int i = 0; i < s.length(); i++) {
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