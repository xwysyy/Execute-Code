#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int qCount = 0;
        for (char c : s) {
            if (c == 'Q') {
                qCount++;
            } else if (c == 'A') {
                if (qCount > 0) {
                    qCount--;
                }
            }
        }
        return (qCount == 0) ? "YES" : "NO";
    }
};


#endif