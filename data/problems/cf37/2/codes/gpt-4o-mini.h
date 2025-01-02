#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {   
        // The characters to remove
        int removeCount = 0;
        
        // We will scan through the string looking for the substrings "pie" and "map".
        for (int i = 0; i < n; ++i) {
            // Check for "pie"
            if (i + 2 < n && s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e') {
                removeCount += 3; // Remove "pie", add up to remove count
                // Safely skip the next two characters since we have "pie"
                i += 2; 
            } 
            // Check for "map"
            else if (i + 2 < n && s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p') {
                removeCount += 3; // Remove "map", add up to remove count
                // Safely skip the next two characters since we have "map"
                i += 2;
            }
        }
        
        // Total number of characters to remove to make the string beautiful
        return removeCount;
    }
};


#endif