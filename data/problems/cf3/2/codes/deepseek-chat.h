#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        // Check if the starting cell or the destination cell is a trap
        if (s1[0] == '1' || s2[n-1] == '1') {
            return "NO";
        }
        
        // Iterate through the columns to check for any impassable columns
        for (int i = 1; i < n; ++i) {
            if (s1[i] == '1' && s2[i] == '1') {
                return "NO";
            }
        }
        
        return "YES";
    }
};


#endif