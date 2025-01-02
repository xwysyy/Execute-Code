#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            // Check if the current room is returnable
            bool canLeave = (s[i] == '>' || s[i] == '-');
            bool canReturn = (s[(i - 1 + n) % n] == '<' || s[(i - 1 + n) % n] == '-');
            if (canLeave && canReturn) {
                count++;
            }
        }
        return count;
    }
};

#endif