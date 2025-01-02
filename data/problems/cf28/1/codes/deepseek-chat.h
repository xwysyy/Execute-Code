#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        // Since both strings start with '0' and end with '1', we can directly compare them
        // If they are already equal, return "YES"
        if (a == b) {
            return "YES";
        }
        
        // The operation allows us to change the characters between two equal characters
        // This means that the positions of '0's and '1's can be adjusted, but the overall
        // structure of the string (starting with '0' and ending with '1') remains the same.
        
        // To make the strings equal, the positions of '0's and '1's in both strings must
        // be such that they can be transformed into each other using the allowed operations.
        
        // Since both strings start with '0' and end with '1', and the operation can only
        // change the characters between two equal characters, the only way to make the
        // strings equal is if they have the same sequence of '0's and '1's.
        
        // Therefore, we can check if the sequences of '0's and '1's in both strings are the same.
        
        // Extract the sequence of '0's and '1's from both strings
        string seq_a, seq_b;
        for (char c : a) {
            if (seq_a.empty() || seq_a.back() != c) {
                seq_a.push_back(c);
            }
        }
        for (char c : b) {
            if (seq_b.empty() || seq_b.back() != c) {
                seq_b.push_back(c);
            }
        }
        
        // If the sequences are the same, return "YES", otherwise "NO"
        return (seq_a == seq_b) ? "YES" : "NO";
    }
};


#endif