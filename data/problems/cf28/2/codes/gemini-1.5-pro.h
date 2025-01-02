#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        string a_simplified = "";
        string b_simplified = "";

        for (int i = 0; i < a.length(); ++i) {
            if (a_simplified.empty() || a[i] != a_simplified.back()) {
                a_simplified += a[i];
            }
        }

        for (int i = 0; i < b.length(); ++i) {
            if (b_simplified.empty() || b[i] != b_simplified.back()) {
                b_simplified += b[i];
            }
        }

        return a_simplified == b_simplified ? "YES" : "NO";
    }
};


#endif