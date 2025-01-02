#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a, string &s) {   
        unordered_map<int, char> numToChar;
        unordered_map<char, int> charToNum;
        
        for (int i = 0; i < n; ++i) {
            int num = a[i];
            char ch = s[i];
            
            if (numToChar.count(num) && numToChar[num] != ch) {
                return "NO";
            }
            if (charToNum.count(ch) && charToNum[ch] != num) {
                return "NO";
            }
            
            numToChar[num] = ch;
            charToNum[ch] = num;
        }
        
        return "YES";
    }
};


#endif