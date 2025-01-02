#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        int n = a.length();
        
        // Create arrays to store the next occurrence of each character (0 or 1)
        vector<int> nextA0(n), nextA1(n);
        vector<int> nextB0(n), nextB1(n);
        
        // Fill next occurrence arrays for string a
        int last0 = n, last1 = n;
        for (int i = n-1; i >= 0; i--) {
            nextA0[i] = last0;
            nextA1[i] = last1;
            if (a[i] == '0') last0 = i;
            else last1 = i;
        }
        
        // Fill next occurrence arrays for string b
        last0 = n; last1 = n;
        for (int i = n-1; i >= 0; i--) {
            nextB0[i] = last0;
            nextB1[i] = last1;
            if (b[i] == '0') last0 = i;
            else last1 = i;
        }
        
        // Check if characters can be made equal at each position
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            
            // Try to match characters using the operation
            bool canMatch = false;
            
            // Check if we can change a[i]
            if (i > 0) {
                char prevChar = a[i-1];
                int next = (prevChar == '0' ? nextA0[i-1] : nextA1[i-1]);
                if (next < n && next > i) canMatch = true;
            }
            
            // Check if we can change b[i]
            if (i > 0 && !canMatch) {
                char prevChar = b[i-1];
                int next = (prevChar == '0' ? nextB0[i-1] : nextB1[i-1]);
                if (next < n && next > i) canMatch = true;
            }
            
            if (!canMatch) return "NO";
        }
        
        return "YES";
    }
};


#endif