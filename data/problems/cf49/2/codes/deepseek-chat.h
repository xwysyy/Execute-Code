#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n % 2 != 0) {
            // If the length is odd, we need to delete one character to make it even
            // So we consider all possible deletions and find the minimum operations
            int minOps = INT_MAX;
            for (int i = 0; i < n; ++i) {
                string temp = s;
                temp.erase(i, 1);
                int ops = 0;
                char oddChar = temp[0];
                char evenChar = temp[1];
                for (int j = 0; j < temp.length(); ++j) {
                    if (j % 2 == 0) {
                        if (temp[j] != oddChar) {
                            ops++;
                        }
                    } else {
                        if (temp[j] != evenChar) {
                            ops++;
                        }
                    }
                }
                minOps = min(minOps, ops);
            }
            return minOps + 1; // +1 for the deletion operation
        } else {
            // If the length is even, we don't need to delete any character
            // We just need to make sure that characters in even positions are the same and characters in odd positions are the same
            int ops1 = 0, ops2 = 0;
            char oddChar1 = s[0], evenChar1 = s[1];
            char oddChar2 = s[1], evenChar2 = s[0];
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) {
                    if (s[i] != oddChar1) {
                        ops1++;
                    }
                    if (s[i] != oddChar2) {
                        ops2++;
                    }
                } else {
                    if (s[i] != evenChar1) {
                        ops1++;
                    }
                    if (s[i] != evenChar2) {
                        ops2++;
                    }
                }
            }
            return min(ops1, ops2);
        }
    }
};


#endif