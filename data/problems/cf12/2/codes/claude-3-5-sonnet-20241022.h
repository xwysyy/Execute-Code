#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        // Check if dialog starts with a question
        if (s[0] != 'Q') return "NO";
        
        int questions = 0;  // Count of questions so far
        int answers = 0;    // Count of answers so far
        
        for (char c : s) {
            if (c == 'Q') {
                questions++;
                // If we have more questions than answers at any point
                // after the first question, it means some question has no answer
                if (questions > answers + 1) return "NO";
            } else {
                answers++;
            }
        }
        
        // Final check: each question must have at least one answer
        return (answers >= questions) ? "YES" : "NO";
    }
};


#endif