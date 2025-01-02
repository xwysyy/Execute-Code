#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a, string &s) {
        unordered_set<int> unique_numbers(a.begin(), a.end());
        unordered_set<char> unique_characters(s.begin(), s.end());

        if (unique_characters.size() <= unique_numbers.size()) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif