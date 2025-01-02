#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        int n = a.length();
        // Since both strings start with '0' and end with '1', we can directly compare them
        // The key insight is that the operations can only change the characters between two equal characters
        // Therefore, the positions of '0's and '1's in both strings must be the same
        // We can check if the sequences of '0's and '1's are the same in both strings
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                return "NO";
            }
        }
        return "YES";
    }
};


#endif