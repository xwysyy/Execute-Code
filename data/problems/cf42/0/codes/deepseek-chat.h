#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int count = 0;
        for (char c : s) {
            if (c == 'U') {
                count++;
            }
        }
        // If the number of facing-up coins is odd, Alice wins
        if (count % 2 == 1) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif