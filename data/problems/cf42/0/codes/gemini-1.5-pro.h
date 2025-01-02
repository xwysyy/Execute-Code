#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int up_count = 0;
        for (char c : s) {
            if (c == 'U') {
                up_count++;
            }
        }
        if (up_count == 1 || up_count % 2 == 0) {
            return "NO";
        } else {
            return "YES";
        }
    }
};


#endif