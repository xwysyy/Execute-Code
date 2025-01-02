#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int qCount = 0; // Counter for unanswered queries
        for (char c : s) {
            if (c == 'Q') {
                qCount++; // Increment for each new query
            } else if (c == 'A') {
                if (qCount > 0) {
                    qCount--; // Decrement for each answer that resolves a query
                }
            }
        }
        // If all queries are answered, return "YES", else "NO"
        return (qCount == 0) ? "YES" : "NO";
    }
};


#endif