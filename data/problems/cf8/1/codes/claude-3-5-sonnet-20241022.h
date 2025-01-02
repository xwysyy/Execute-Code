#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a, string &s) {
        // For each position, numbers that are equal in array 'a'
        // must correspond to equal letters in string 's'
        // and different numbers must correspond to different letters
        
        // Check if lengths match
        if (a.size() != s.length()) return "NO";
        
        // Map to store number to letter mapping
        unordered_map<int, char> num_to_char;
        // Map to store letter to number mapping
        unordered_map<char, int> char_to_num;
        
        // Check each position
        for (int i = 0; i < n; i++) {
            // If number already mapped
            if (num_to_char.count(a[i])) {
                // Check if it maps to the same letter
                if (num_to_char[a[i]] != s[i]) {
                    return "NO";
                }
            }
            // If letter already mapped
            else if (char_to_num.count(s[i])) {
                // Check if it maps to the same number
                if (char_to_num[s[i]] != a[i]) {
                    return "NO";
                }
            }
            // New mapping
            else {
                num_to_char[a[i]] = s[i];
                char_to_num[s[i]] = a[i];
            }
        }
        
        return "YES";
    }
};


#endif