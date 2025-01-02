#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int countUp = 0;

        // Count the number of 'U's
        for (char c : s) {
            if (c == 'U') {
                countUp++;
            }
        }

        // Determine winner based on the parity of countUp
        if (countUp % 2 == 1) {
            return "YES"; // Alice wins
        } else {
            return "NO"; // Bob wins
        }
    }
};


#endif