#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int unanswered_questions = 0;
        
        for (char message : s) {
            if (message == 'Q') {
                unanswered_questions++;
            } 
            else if (message == 'A') {
                // If we receive an 'A', it can answer an outstanding question
                if (unanswered_questions > 0) {
                    unanswered_questions--;
                }
            }
            // If we have an 'A' but no unanswered questions, it's still valid
        }
        
        // After processing all messages, if there are any unanswered questions left
        return unanswered_questions > 0 ? "NO" : "YES";
    }
};


#endif