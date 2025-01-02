#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a, string &s) {
        unordered_set<int> unique_numbers(a.begin(), a.end()); // Get unique numbers from array
        unordered_set<char> unique_characters(s.begin(), s.end()); // Get unique characters from string

        // Check if we have enough unique letters to correspond to the unique numbers
        if (unique_numbers.size() <= unique_characters.size()) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif