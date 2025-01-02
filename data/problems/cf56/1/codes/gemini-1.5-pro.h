#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &m, int &k, string &s) {
        int count = 0;
        for (int i = 0; i <= n - m; ++i) {
            bool all_zero = true;
            for (int j = 0; j < m; ++j) {
                if (s[i + j] == '1') {
                    all_zero = false;
                    break;
                }
            }
            if (all_zero) {
                count++;
                for (int j = 0; j < k; ++j) {
                    if (i + j < n) {
                        s[i + j] = '1';
                    }
                }
                i += (m -1);
            }
        }
        return count;
    }
};


#endif