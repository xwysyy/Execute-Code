#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        string a_simplified = simplify(a);
        string b_simplified = simplify(b);
        return a_simplified == b_simplified ? "YES" : "NO";
    }

private:
    string simplify(string s) {
        string result = "";
        for (char c : s) {
            if (result.empty() || result.back() != c) {
                result += c;
            }
        }
        return result;
    }
};


#endif