#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int clientQuestions = 0;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'Q') {
                clientQuestions++;
            } else if (s[i] == 'A') {
                if (clientQuestions == 0) {
                    return "NO";
                }
                clientQuestions--;
            }
        }
        
        return clientQuestions == 0 ? "YES" : "NO";
    }
};

#endif