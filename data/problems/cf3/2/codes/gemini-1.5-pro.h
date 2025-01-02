#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        if (s1[0] == '1' && s2[0] == '1') return "NO";
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '1' && s2[i] == '1') return "NO";
        }
        return "YES";
    }
};


#endif