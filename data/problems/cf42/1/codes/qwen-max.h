#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int countU = 0;
        for (char c : s) {
            if (c == 'U') {
                countU++;
            }
        }
        
        // If the number of 'U' is odd, Alice wins, otherwise Bob wins
        return (countU % 2 == 1) ? "YES" : "NO";
    }
};

#endif