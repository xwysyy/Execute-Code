#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int &n, string &s) {
        int balance = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'Q') {
                balance++;
            } else if (s[i] == 'A') {
                balance--;
            }
            // If at any point the number of answers exceeds the number of questions, it's invalid.
            if (balance < 0) {
                return "NO";
            }
        }
        // In the end, all questions must be answered.
        return balance == 0 ? "YES" : "NO";
    }
};

#endif