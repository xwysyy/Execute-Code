#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        // Check if there are any 'N' in the string
        bool hasN = false;
        for (char c : s) {
            if (c == 'N') {
                hasN = true;
                break;
            }
        }
        
        // If there are no 'N's, it's always consistent
        if (!hasN) {
            return "YES";
        }
        
        // If the string ends and starts with 'E', there would be a conflict
        if (s[0] == 'E' && s[n - 1] == 'E') {
            return "NO";
        }
        
        // If there are consecutive 'N's separating 'E's, it can be consistent
        return "YES";
    }
};


#endif