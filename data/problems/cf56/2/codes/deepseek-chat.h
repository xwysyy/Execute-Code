#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, string &s) {
        int count = 0;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                // Check if the next m characters are all '0's
                bool allZero = true;
                for (int j = i; j < i + m && j < n; ++j) {
                    if (s[j] != '0') {
                        allZero = false;
                        break;
                    }
                }
                if (allZero) {
                    // Use Timar on the segment starting at i
                    count++;
                    // Strengthen the next k characters
                    for (int j = i; j < i + k && j < n; ++j) {
                        s[j] = '1';
                    }
                    i += k; // Move i by k positions
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }
        return count;
    }
};


#endif