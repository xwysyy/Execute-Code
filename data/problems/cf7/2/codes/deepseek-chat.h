#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {
        int total = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                // Check if moving the lid to the left box is better
                if (i > 0 && s[i-1] == '0' && a[i-1] > a[i]) {
                    total += a[i-1];
                    s[i-1] = '1'; // Mark the left box as covered
                } else {
                    total += a[i];
                }
            }
        }
        return total;
    }
};


#endif