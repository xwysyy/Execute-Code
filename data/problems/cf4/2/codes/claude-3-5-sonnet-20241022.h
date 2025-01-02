#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        // For n elements, we need exactly n characters in s
        // Each character represents relationship between adjacent elements
        
        // Count the number of 'N' (not equal) relationships
        int notEqual = 0;
        for(char c : s) {
            if(c == 'N') notEqual++;
        }
        
        // If all relationships are 'E' (equal), all numbers should be same
        // This is always possible, so return "YES"
        if(notEqual == 0) return "YES";
        
        // If there is exactly one 'N', it's impossible
        // Because we need to return to the starting point
        if(notEqual == 1) return "NO";
        
        // If number of 'N' is odd, it's impossible
        // Because when we go around the circle, we need even number of changes
        // to return to the starting value
        if(notEqual % 2 == 1) return "NO";
        
        // In all other cases, we can construct a valid array
        return "YES";
    }
};


#endif