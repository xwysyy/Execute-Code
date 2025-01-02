#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {   
        // We need to check if both strings have at least one '1' and one '0'
        // because we can only stretch characters between equal ones.
        
        bool hasZeroA = false, hasOneA = false;
        bool hasZeroB = false, hasOneB = false;
        
        for (char ch : a) {
            if (ch == '0') hasZeroA = true;
            if (ch == '1') hasOneA = true;
        }
        
        for (char ch : b) {
            if (ch == '0') hasZeroB = true;
            if (ch == '1') hasOneB = true;
        }
        
        // Both strings can be transformed to match each other if
        // both have at least one '0' and at least one '1' because we can
        // fill the space between '0's or '1's.
        if ((hasZeroA && hasOneA) == (hasZeroB && hasOneB)) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif