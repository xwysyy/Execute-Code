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
            bool alternating = true;
            for (int i = 0; i < n; ++i) {
                if (s[i] == s[(i + 1) % n]) {
                    alternating = false;
                    break;
                }
            }
            if (alternating) return "YES";

            return "NO";
        } else {
            int equal_count = 0;
            for (char c : s) {
                if (c == 'E')
                    equal_count++;
            }
            if (equal_count == n)
                return "YES";
            return "YES";
        }
    }
};


#endif