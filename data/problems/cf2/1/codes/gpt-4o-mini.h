#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        // Check if there is any '-' in the string
        if (s.find('-') != string::npos) {
            return n; // All rooms are returnable
        }
        
        // If there are no '-', check for uniformity
        char first = s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] != first) {
                return 0; // Mixed directions, no returnable rooms
            }
        }
        
        // If we reach here, all are '>' or all are '<'
        return 0; // Since all are same and no '-', no returnable rooms
    }
};


#endif