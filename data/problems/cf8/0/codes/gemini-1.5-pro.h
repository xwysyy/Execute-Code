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
            if (mapping.find(a[i]) == mapping.end()) {
                if (reverse_mapping.find(s[i]) == reverse_mapping.end()) {
                    mapping[a[i]] = s[i];
                    reverse_mapping[s[i]] = a[i];
                } else if (reverse_mapping[s[i]] != a[i]) {
                    return "NO";
                }
            } else if (mapping[a[i]] != s[i]) {
                return "NO";
            }
        }
        return "YES";
    }
};


#endif