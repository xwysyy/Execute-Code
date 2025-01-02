#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {   
        // To find the minimum number of characters to remove to make the string beautiful
        // We will look for the indices of "pie" and "map" substrings
        int count = 0;
        for (int i = 0; i < n; ++i) {
            // We check for "pie" from index i
            if (i + 2 < n && s.substr(i, 3) == "pie") {
                count++;
            }
            // We check for "map" from index i
            if (i + 2 < n && s.substr(i, 3) == "map") {
                count++;
            }
        }
        
        // Each occurrence of "pie" or "map" requires us to remove 2 characters (keeping one character)
        return count * 2;
    }
};


#endif