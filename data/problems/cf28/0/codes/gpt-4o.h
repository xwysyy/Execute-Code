#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        bool hasOneInA = false;
        bool hasOneInB = false;
        
        // We assume both strings are the same length
        int n = a.size();
        
        // Check for the presence of at least one '1' in both strings.
        for (int i = 0; i < n; ++i) {
            if (a[i] == '1')
                hasOneInA = true;
            if (b[i] == '1')
                hasOneInB = true;
            
            // If both have '1', we can already determine it's possible
            if (hasOneInA && hasOneInB)
                return "YES";
        }
        
        // If one of the strings does not have '1', it's not possible
        return "NO";
    }
};


#endif