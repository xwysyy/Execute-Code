#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        // Check if both strings have at least one '1' and one '0'
        bool hasZeroA = false, hasOneA = false;
        bool hasZeroB = false, hasOneB = false;

        for (char c : a) {
            if (c == '0') hasZeroA = true;
            else hasOneA = true;
        }
        
        for (char c : b) {
            if (c == '0') hasZeroB = true;
            else hasOneB = true;
        }
        
        // Both strings should have the same type of characters
        if ((hasZeroA == hasZeroB) && (hasOneA == hasOneB)) {
            return "YES";
        }
        return "NO";
    }
};


#endif