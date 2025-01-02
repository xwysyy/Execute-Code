#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, string &s) {
        int count = 0;
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                // Use Timar on the segment starting at i of length k
                count++;
                i += k; // Move k steps ahead
            } else {
                i++; // Move to the next character
            }
        }
        return count;
    }
};


#endif