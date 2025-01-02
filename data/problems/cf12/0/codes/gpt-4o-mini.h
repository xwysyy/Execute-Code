#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int questionCount = 0;
        
        for (char c : s) {
            if (c == 'Q') {
                questionCount++;
            } else if (c == 'A') {
                // An answer can only be given if there are outstanding questions
                if (questionCount > 0) {
                    questionCount--;
                } else {
                    return "NO"; // More answers than questions
                }
            }
        }
        
        // After scanning through, there should be no remaining questions without answers
        return questionCount == 0 ? "YES" : "NO";
    }
};


#endif