#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int questions = 0;  // Count of questions seen so far
        int answers = 0;    // Count of answers seen so far
        
        // For each message in the dialog
        for (int i = 0; i < n; i++) {
            if (s[i] == 'Q') {
                questions++;
            } else {
                answers++;
            }
            
            // At any point, if we have more questions than answers + 1,
            // it means some question has no answer
            if (questions > answers + 1) {
                return "NO";
            }
        }
        
        // Final check: number of answers should be at least equal to questions
        return (answers >= questions) ? "YES" : "NO";
    }
};


#endif