#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        // Count the number of 'N's in the string
        int countN = count(s.begin(), s.end(), 'N');

        // If there is at least one 'N', we need at least two distinct values
        if (countN > 0) {
            // Check if there are adjacent 'N's which violate the circle condition
            // If 'N' is present and adjacent elements are enforced to be equal,
            // it will lead to contradiction.
            // If there is at least one 'N', we can use two distinct numbers.
            return "YES";
        } else {
            // All 'E's means we can construct with one distinct number
            return "YES";
        }
    }
};


#endif