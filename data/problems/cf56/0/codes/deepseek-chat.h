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
                // Check if the next m-1 characters are also '0'
                bool allZero = true;
                for (int j = i; j < i + m && j < n; ++j) {
                    if (s[j] != '0') {
                        allZero = false;
                        break;
                    }
                }
                if (allZero) {
                    // Use Timar on the segment starting at i of length k
                    count++;
                    i += k; // Move i by k since we've strengthened this segment
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