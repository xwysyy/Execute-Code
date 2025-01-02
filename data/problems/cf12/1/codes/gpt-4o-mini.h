#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int questions = 0; // Count of unanswered questions
        
        for (char c : s) {
            if (c == 'Q') {
                questions++; // New question increases the count
            } else if (c == 'A') {
                if (questions > 0) {
                    questions--; // Answer corresponds to one question
                } else {
                    return "NO"; // An answer without a corresponding question
                }
            }
        }
        
        // After processing all messages, there shouldn't be any unanswered questions
        return questions == 0 ? "YES" : "NO";
    }
};


#endif