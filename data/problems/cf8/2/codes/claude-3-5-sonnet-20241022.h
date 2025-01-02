#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a, string &s) {
        // Create a map to store the first occurrence of each number
        vector<int> firstOccurrence(n + 1, -1);
        
        // Check if the pattern of equal numbers matches the pattern of equal letters
        for (int i = 0; i < n; i++) {
            // If this number was seen before
            if (firstOccurrence[a[i]] != -1) {
                // The corresponding letters must be the same
                if (s[i] != s[firstOccurrence[a[i]]]) {
                    return "NO";
                }
            } else {
                // For each new number, check if its letter was already 
                // assigned to a different number
                for (int j = 1; j <= n; j++) {
                    if (firstOccurrence[j] != -1 && 
                        s[firstOccurrence[j]] == s[i] && 
                        a[i] != j) {
                        return "NO";
                    }
                }
                firstOccurrence[a[i]] = i;
            }
        }
        
        return "YES";
    }
};


#endif