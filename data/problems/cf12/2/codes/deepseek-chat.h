#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int qCount = 0; // To keep track of unanswered queries
        for (char c : s) {
            if (c == 'Q') {
                qCount++; // Increment for each query
            } else if (c == 'A') {
                if (qCount > 0) {
                    qCount--; // Decrement if there's an unanswered query
                }
            }
        }
        // If all queries are answered, return "YES", else "NO"
        return (qCount == 0) ? "YES" : "NO";
    }
};


#endif