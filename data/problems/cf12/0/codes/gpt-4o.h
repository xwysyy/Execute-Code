#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int unanswered = 0; // to count unanswered questions
        
        for (char c : s) {
            if (c == 'Q') {
                unanswered++; // we have one more new question
            } else if (c == 'A') {
                if (unanswered > 0) {
                    unanswered--; // answer a previous question
                } // If unanswered is 0, excess answers don't affect the validity, so do nothing
            }
        }
        
        // if there are still unanswered questions at the end, return "NO"
        if (unanswered > 0) {
            return "NO";
        }
        return "YES";
    }
};


#endif