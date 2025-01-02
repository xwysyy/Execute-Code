#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        // Check if there is at least one obstacle belt (off state)
        if (s.find('-') != string::npos) {
            return n; // All rooms are returnable
        }
        
        // If we only have '>' and '<'
        // Check if all are the same ['>' or '<']
        bool allClockwise = true, allAnticlockwise = true;

        for (char c : s) {
            if (c != '>') allClockwise = false; // If there's any '<' or '-', not all are clockwise
            if (c != '<') allAnticlockwise = false; // If there's any '>' or '-', not all are anticlockwise
        }

        // If all are '>' or all are '<', all rooms are returnable
        return allClockwise || allAnticlockwise ? n : 0;
    }
};


#endif