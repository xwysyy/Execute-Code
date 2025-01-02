#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int balance = 0;
        for (char c : s) {
            if (c == 'Q') {
                balance++;
            } else {
                balance--;
            }
            if (balance < 0) {
                return "NO";
            }
        }
        if (balance > 0) {
            return "NO";
        }
        return "YES";
    }
};


#endif