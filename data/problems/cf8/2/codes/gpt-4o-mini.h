#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a, string &s) {
        if (n != s.length()) return "NO"; // Length must match

        unordered_map<int, char> numToChar; // Map to store which number corresponds to which character
        for (int i = 0; i < n; i++) {
            int num = a[i];
            char ch = s[i];

            // If the number has already been mapped to a different character 
            // than what we need here, return "NO"
            if (numToChar.count(num)) {
                if (numToChar[num] != ch) {
                    return "NO";
                }
            } else {
                // Map the number to the character
                numToChar[num] = ch;
            }
        }
        return "YES"; // All conditions satisfied
    }
};


#endif