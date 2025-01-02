#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a, string &s) {
        // Create a mapping from numbers to characters
        unordered_map<int, char> numToChar;
        // Create a mapping from characters to numbers
        unordered_map<char, int> charToNum;

        for (int i = 0; i < n; ++i) {
            int num = a[i];
            char ch = s[i];

            // If the number is already mapped to a character
            if (numToChar.find(num) != numToChar.end()) {
                // Check if the mapped character matches the current character in the string
                if (numToChar[num] != ch) {
                    return "NO";
                }
            } else {
                // If the character is already mapped to a number
                if (charToNum.find(ch) != charToNum.end()) {
                    // Check if the mapped number matches the current number in the array
                    if (charToNum[ch] != num) {
                        return "NO";
                    }
                } else {
                    // Map the number to the character and vice versa
                    numToChar[num] = ch;
                    charToNum[ch] = num;
                }
            }
        }
        return "YES";
    }
};


#endif