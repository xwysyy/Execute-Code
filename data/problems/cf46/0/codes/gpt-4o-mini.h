#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) {
        int count = 0;

        // Loop through each column
        for (int i = 0; i < n; ++i) {
            // Check if current cell is '.'
            if (s1[i] == '.' || s2[i] == '.') {
                bool topConnected = (i > 0) && (s1[i] == '.' && s1[i - 1] == '.');
                bool bottomConnected = (i > 0) && (s2[i] == '.' && s2[i - 1] == '.');
                bool verticalConnected = (s1[i] == '.' && s2[i] == '.');

                // Check conditions for creating exactly 3 components when blocking
                if ((s1[i] == '.' && !topConnected && !verticalConnected) || 
                    (s2[i] == '.' && !bottomConnected && !verticalConnected)) {
                    count++;
                }
            }
        }

        return count;
    }
};


#endif