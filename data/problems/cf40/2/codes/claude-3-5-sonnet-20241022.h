#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s) {
        int n = s.length();
        int maxLen = 0;
        
        // Try all possible substrings
        for (int i = 0; i < n; i++) {
            for (int len = 2; i + len <= n; len += 2) {
                // Check if current substring of length 'len' starting at 'i'
                // can form a tandem repeat
                bool possible = true;
                int halfLen = len / 2;
                
                // Compare first half with second half
                for (int j = 0; j < halfLen && possible; j++) {
                    char first = s[i + j];
                    char second = s[i + j + halfLen];
                    
                    if (first != '?' && second != '?' && first != second) {
                        possible = false;
                    }
                }
                
                if (possible) {
                    maxLen = max(maxLen, len);
                }
            }
        }
        
        return maxLen;
    }
};


#endif