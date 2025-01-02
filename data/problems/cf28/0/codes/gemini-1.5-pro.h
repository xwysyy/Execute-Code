#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        int n = a.length();
        vector<int> a_ones, b_ones;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '1') {
                a_ones.push_back(i);
            }
            if (b[i] == '1') {
                b_ones.push_back(i);
            }
        }

        if (a_ones.size() != b_ones.size()) {
            return "NO";
        }

        for (int i = 0; i < a_ones.size(); ++i) {
            if (a_ones[i] > b_ones[i]) {
                return "NO";
            }
        }
        return "YES";
    }
};


#endif