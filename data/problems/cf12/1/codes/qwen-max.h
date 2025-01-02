#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int client_questions = 0;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'Q') {
                client_questions++;
            } else if (s[i] == 'A') {
                if (client_questions == 0) {
                    return "NO";
                }
                client_questions--;
            }
        }
        
        return client_questions == 0 ? "YES" : "NO";
    }
};

#endif