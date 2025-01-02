#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, string &s) {
        int operations = 0;
        int i = 0;
        while (i <= n - m) {
            if (s.substr(i, m).find('1') == string::npos) { // Check if there's an entirely weak segment of length m
                operations++;
                for (int j = max(0, i - k + 1); j < min(n, i + m); j++) {
                    s[j] = '1'; // Strengthen the segment
                }
            } else {
                i++; // Move to the next position
            }
        }
        return operations;
    }
};

#endif