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
            if (s.substr(i, m).find('1') == string::npos) {
                // If there's a segment of length m with all 0s
                s[i + m - k] = '2'; // Mark the start of the strengthened segment
                for (int j = 1; j < k; ++j) {
                    if (i + m - k + j < n) {
                        s[i + m - k + j] = '1';
                    }
                }
                operations++;
            }
            // Skip over any already strengthened or naturally strong spots
            while (i < n && (s[i] == '1' || s[i] == '2')) {
                i++;
            }
        }
        return operations;
    }
};

#endif