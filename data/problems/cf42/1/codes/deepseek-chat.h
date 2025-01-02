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
        // If the count of 'U' is odd, Alice wins; otherwise, Bob wins.
        return (count % 2 == 1) ? "YES" : "NO";
    }
};


#endif