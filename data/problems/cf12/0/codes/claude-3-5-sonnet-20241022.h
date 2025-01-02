#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        // Check if dialog starts with a question
        if (s[0] != 'Q') return "NO";
        
        int questions = 0;
        int answers = 0;
        
        // Count questions and answers
        for (char c : s) {
            if (c == 'Q') {
                questions++;
            } else {
                answers++;
            }
            
            // At any point, we can't have more questions than answers + 1
            // because each question needs at least one answer
            if (questions > answers + 1) {
                return "NO";
            }
        }
        
        // Final check: total answers must be at least equal to questions
        return (answers >= questions) ? "YES" : "NO";
    }
};


#endif