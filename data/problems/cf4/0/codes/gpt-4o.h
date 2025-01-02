#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        // If there's no 'E' or all are 'E', then it's directly possible
        if (s.find('N') == string::npos || s.find('E') == string::npos) {
            return "YES";
        }
        
        // Finding inconsistent situation with even and odd positions
        // Essentially we want to see if we have an odd-length cycle with inconsistent 'N's
        int even_group = -1;
        int odd_group = -1;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'E') {
                even_group = i % 2;
                odd_group = 1 - even_group;
                break;
            }
        }
        
        if (even_group == -1)
            return "YES"; // No "E", only 'N's mean possible alternation
        
        // Check for impossible 'N's
        for (int i = 0; i < n; i++) {
            if (s[i] == 'N' && (i % 2 == even_group)) {
                // If we're in an 'E' cycle parity and have a contradiction
                return "NO";
            }
        }
        
        return "YES";
    }
};


#endif