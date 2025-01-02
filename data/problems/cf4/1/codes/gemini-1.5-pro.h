#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        if (n % 2 == 1) {
            bool all_equal = true;
            for (char c : s) {
                if (c == 'N') {
                    all_equal = false;
                    break;
                }
            }
            if (all_equal) return "YES";
            bool possible = true;
            for (int i = 0; i < n; ++i) {
                if (s[i] == s[(i + 1) % n]) {
                    possible = false;
                    break;
                }
            }
            return possible ? "YES" : "NO";
        } else {
            int count_n = 0;
            for (char c : s) {
                if (c == 'N') {
                    count_n++;
                }
            }
            if (count_n % 2 == 1)
                return "NO";
            else
                return "YES";
        }
    }
};


#endif