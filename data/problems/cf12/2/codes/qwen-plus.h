#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int balance = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'Q') {
                balance++;
            } else if (s[i] == 'A') {
                balance--;
            }
            // If at any point the number of answers exceeds the number of questions,
            // or if we have a question after all questions should be answered, return "NO".
            if (balance < 0 || (balance == 0 && i < n - 1 && s[i + 1] == 'A')) {
                return "NO";
            }
        }
        // In the end, there should be no unanswered questions.
        return balance == 0 ? "YES" : "NO";
    }
};


#endif