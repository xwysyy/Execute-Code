#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // If the starting or ending cell is a trap, return "NO"
        if (s1[0] == '1' || s2[0] == '1' || s1[n-1] == '1' || s2[n-1] == '1') {
            return "NO";
        }

        // Iterate through each column
        for (int i = 0; i < n; ++i) {
            // If both cells in the current column are traps, return "NO"
            if (s1[i] == '1' && s2[i] == '1') {
                return "NO";
            }
            // If one of the cells in the current column is not a trap, continue
            if (s1[i] == '0' || s2[i] == '0') {
                continue;
            }
        }

        // If we can reach the end, return "YES"
        return "YES";
    }
};

#endif