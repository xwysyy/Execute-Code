#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        // If all conveyor belts are off, all rooms are returnable
        if (s.find_first_not_of('-') == string::npos) {
            return n;
        }
        
        // Check for continuous '>' or '<' which would block returnability
        bool clockwiseBlocked = s.find_first_of('<') != string::npos && s.find_last_of('>') != string::npos && s.find_last_of('>') > s.find_first_of('<');
        bool anticlockwiseBlocked = s.find_first_of('>') != string::npos && s.find_last_of('<') != string::npos && s.find_last_of('<') > s.find_first_of('>');

        if (clockwiseBlocked || anticlockwiseBlocked) {
            return 0;
        }

        // If none of the above conditions are met, all rooms are returnable
        return n;
    }
};


#endif