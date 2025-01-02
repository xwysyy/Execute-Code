#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, string &s) {
        if (n % 2 != 0) {
            return 1;
        }
        int even_diff = 0;
        int odd_diff = 0;
        char even_char = ' ';
        char odd_char = ' ';
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (even_char == ' ') {
                    even_char = s[i];
                } else if (s[i] != even_char) {
                    even_diff++;
                }
            } else {
                if (odd_char == ' ') {
                    odd_char = s[i];
                } else if (s[i] != odd_char) {
                    odd_diff++;
                }
            }
        }
        return even_diff + odd_diff;
    }
};


#endif