#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int &n, string &s) {
        int customerQuestions = 0;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'Q') {
                customerQuestions++;
            } else if (s[i] == 'A') {
                if (customerQuestions == 0) {
                    return "NO";
                }
                customerQuestions--;
            }
        }
        
        return customerQuestions == 0 ? "YES" : "NO";
    }
};

#endif