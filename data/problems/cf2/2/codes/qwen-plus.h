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
        
        // Check for continuous '>' or '<' which would block return paths
        bool clockwiseBlocked = s.find_first_of('<') != string::npos && s.find_last_of('>') != string::npos;
        bool anticlockwiseBlocked = s.find_first_of('>') != string::npos && s.find_last_of('<') != string::npos;

        // If both directions have at least one active conveyor, no room is returnable
        if (clockwiseBlocked && anticlockwiseBlocked) {
            return 0;
        }

        // If only one direction has active conveyors, all rooms are returnable
        return n;
    }
};


#endif