#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n % 2 != 0) {
            return 1;
        }

        int even_diff = 0;
        for (int i = 0; i < n; i += 2) {
            if (s[i] != s[0]) {
                even_diff++;
            }
        }

        int odd_diff = 0;
        for (int i = 1; i < n; i += 2) {
            if (s[i] != s[1]) {
                odd_diff++;
            }
        }

        return min(even_diff + odd_diff, (n / 2) );

    }
};


#endif