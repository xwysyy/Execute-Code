#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &m, int &k, string &s) {
        int count = 0;
        for (int i = 0; i <= n - m; ) {
            bool all_zeros = true;
            for (int j = i; j < i + m; ++j) {
                if (s[j] == '1') {
                    all_zeros = false;
                    break;
                }
            }
            if (all_zeros) {
                count++;
                for (int j = i; j < min(i + k, n); ++j) {
                    s[j] = '1';
                }
                i += m;
            } else {
                i++;
            }
        }
        return count;
    }
};


#endif