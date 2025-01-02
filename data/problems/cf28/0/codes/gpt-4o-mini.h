#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        // Check if both strings have '1' and '0' in them
        bool hasOneA = false, hasOneB = false;
        bool hasZeroA = false, hasZeroB = false;
        
        for (char c : a) {
            if (c == '1') hasOneA = true;
            if (c == '0') hasZeroA = true;
        }
        
        for (char c : b) {
            if (c == '1') hasOneB = true;
            if (c == '0') hasZeroB = true;
        }
        
        // To make both strings equal, both must have at least one '1' and one '0'
        if ((hasOneA && hasZeroA) == (hasOneB && hasZeroB)) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif