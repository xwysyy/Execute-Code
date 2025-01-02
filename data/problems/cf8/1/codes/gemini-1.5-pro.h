#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a, string &s) {
        map<int, char> mapping;
        map<char, int> reverse_mapping;

        for (int i = 0; i < n; ++i) {
            if (mapping.count(a[i])) {
                if (mapping[a[i]] != s[i]) {
                    return "NO";
                }
            } else {
                if (reverse_mapping.count(s[i])) {
                    return "NO";
                }
                mapping[a[i]] = s[i];
                reverse_mapping[s[i]] = a[i];
            }
        }
        return "YES";
    }
};


#endif