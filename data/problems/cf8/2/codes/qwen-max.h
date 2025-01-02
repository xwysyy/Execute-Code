#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a, string &s) {   
        if (n != s.length()) return "NO";
        
        unordered_map<int, char> numToChar;
        unordered_set<char> usedChars;
        
        for (int i = 0; i < n; ++i) {
            if (numToChar.find(a[i]) == numToChar.end()) {
                if (usedChars.find(s[i]) != usedChars.end()) {
                    return "NO";
                }
                numToChar[a[i]] = s[i];
                usedChars.insert(s[i]);
            } else if (numToChar[a[i]] != s[i]) {
                return "NO";
            }
        }
        
        return "YES";
    }
};

#endif