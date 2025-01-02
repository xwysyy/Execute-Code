#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {   
        // Check if both strings have at least one '0' and one '1'
        bool hasZeroA = false, hasOneA = false;
        bool hasZeroB = false, hasOneB = false;
        
        for (char ch : a) {
            if (ch == '0') hasZeroA = true;
            if (ch == '1') hasOneA = true;
            if (hasZeroA && hasOneA) break;
        }

        for (char ch : b) {
            if (ch == '0') hasZeroB = true;
            if (ch == '1') hasOneB = true;
            if (hasZeroB && hasOneB) break;
        }
        
        // Both need to contain at least one '0' and one '1' to even be transformable
        return (hasZeroA && hasOneA && hasZeroB && hasOneB) ? "YES" : "NO";
    }
};


#endif